#include "camera.h"

#include <GL/gl.h>
#include <iostream>

Camera::Camera()
{
    m_position = glm::vec3(0.0f, 0.0f, 5.0f);
    m_target = glm::vec3(0.0f, 0.0f, -1.0f);
    m_up = glm::vec3(0.0f, 1.0f, 0.0f);
    
    
    m_yaw = 0.0f;
    m_pitch = -20.0f;
    m_distance = 30.0f; //10.0f
    m_angleAround = 90.0f;
}

Camera::~Camera()
{
    
}

glm::mat4 * Camera::getView()
{
    float horizontalDistance = m_distance * cos(glm::radians(m_pitch));
    float verticalDistance = m_distance * sin(glm::radians(-m_pitch));
    
    m_position.y = verticalDistance;
    m_position.x = horizontalDistance * cos(glm::radians(m_angleAround)) + m_target.x;
    m_position.z = horizontalDistance * sin(glm::radians(m_angleAround)) + m_target.z;    
    
    //m_position -= glm::normalize(glm::cross(m_front, m_up)) * 0.01f;
    //m_position -= -0.02f * m_front;
     
    m_yaw = 180 + m_angleAround;
    
    glm::vec3 direction;
    direction.x = cos(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
    direction.y = sin(glm::radians(m_pitch));
    direction.z = sin(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
    m_front = glm::normalize(direction);
        
    m_view = glm::lookAt(m_position, m_position + m_front, m_up);
    
    return &m_view;
}

void Camera::Rotate(const float& angleAround, const float& pitch)
{
    m_pitch += pitch;
    m_angleAround += angleAround;
    
    //if (m_angleX < -0.3f) m_angleX = -0.3f;
    //if (m_angleX > glm::radians(90.0f)) m_angleX = glm::radians(90.0f);
    //if (m_angleY > 1.1f) m_angleY = 1.1f;
    //if (m_angleY < -1.1f) m_angleY = -1.1f;
}

void Camera::Zoom(const float& amount)
{
    m_distance += amount;
    
    if (m_distance <= 1.0f) m_distance = 1.0f;
    else if (m_distance >= 50.0f) m_distance = 50.0f;
    m_position.z = m_distance;
}

void Camera::SetTarget(const glm::vec3 target)
{
    m_target = target;
}


