#include "camera.h"
#include "../Basic/parameters.h"
#include "../Basic/input.h"

Camera::Camera(const float& distance)
{
    m_position = glm::vec3(0.0);
    m_target = glm::vec3(0.0);
    m_up = glm::vec3(0.0, 1.0, 0.0);
    float zFar = 1000;
    float zNear = 1;
    m_projection = glm::perspective(glm::radians(45.0f), (float)parameters::Width/(float)parameters::Height, zNear, zFar);
    
    m_distance = distance;
    m_yaw = 0.0;
    m_pitch = -20.0;
    m_angleAround = 90;
    CalculateView(0, 0);
    blocked = false;
}

Camera::~Camera()
{
    
}

void Camera::Update(const glm::vec3& targetPosition, const float& rotationY, const float& terrainHeight)
{
    m_target = targetPosition;
    if (Input::LeftClick(Input::eMouse::leftButton)) {
        if (abs(Input::MouseOffset().Y) < 300)
            Rotate(0.0, -(float)Input::MouseOffset().Y / 15);
        
        if (abs(Input::MouseOffset().X) < 300)
            Rotate((float)Input::MouseOffset().X / 8, 0.0);
    }
    if (Input::ScrollDown()) Zoom(0.5);
    if (Input::ScrollUp()) Zoom(-0.5);

    CalculateView(rotationY, terrainHeight);
}

void Camera::CalculateView(const float& rotationY, const float& terrainHeight)
{
    float horizontalDistance = m_distance * cos(glm::radians(m_pitch));
    float verticalDistance = m_distance * sin(glm::radians(-m_pitch));
    
    m_position.y = verticalDistance + m_target.y;
    m_position.x = horizontalDistance * cos(glm::radians(m_angleAround) + glm::radians(180 - rotationY)) + m_target.x;
    m_position.z = horizontalDistance * sin(glm::radians(m_angleAround) + glm::radians(180 - rotationY)) + m_target.z;

    m_yaw = 180 + m_angleAround + 180 - rotationY;

    glm::vec3 direction;

    // if (m_position.y < terrainHeight + 1) {
    //     m_position.y = terrainHeight + 1;
    //     blocked = true;
    // } else {
    //     blocked = false;
    // }

    direction.x = cos(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
    direction.y = sin(glm::radians(m_pitch));
    direction.z = sin(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
    
    m_front = glm::normalize(direction);
    m_view = glm::lookAt(m_position, m_position + m_front, m_up);
}

#include <iostream>

void Camera::Rotate(const float& angleAround, const float& pitch)
{
    if (m_pitch > -85 || pitch > 0.1) {
        if (!blocked || pitch < -0.1) m_pitch += pitch;
    }
    m_angleAround += angleAround;

    if (m_angleAround < 0) m_angleAround += 360;
    else if (m_angleAround > 360) m_angleAround -= 360;
}

void Camera::Zoom(const float& amount)
{
    m_distance += amount * (m_distance / 10);
    
    if (m_distance <= 10.0f) m_distance = 10.0f;
    else if (m_distance >= 80.0f) m_distance = 80.0f;
    m_position.z = m_distance;
}

void Camera::SetTarget(const glm::vec3 target)
{
    m_target = target;
}
