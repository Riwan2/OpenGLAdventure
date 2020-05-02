#ifndef CAMERA_H
#define CAMERA_H

#include <glm/gtc/matrix_transform.hpp>

class Camera
{
public:
    Camera(const float& distance);
    ~Camera();
    
    void SetTarget(const glm::vec3 target);
    void Update(const glm::vec3& targetPosition, const float& rotationY, const float& terrainHeight);
private:
    glm::mat4 m_view, m_projection;
    glm::vec3 m_position, m_target, m_front, m_up;
    float m_angleAround, m_yaw, m_pitch, m_distance;
    bool blocked;
    
    void CalculateView(const float& rotationY, const float& terrainHeight);
public:
    void Zoom(const float& amount);
    void Rotate(const float& angleY, const float& angleX);
    const glm::mat4& GetView() const { return m_view; }
    const glm::mat4& GetProjection() const { return m_projection; }
    const float& GetAngleAround() const { return m_angleAround; }
    const float& GetPitch() const { return m_pitch; }
    const glm::vec3 GetPosition() const { return m_position; }
};

#endif // CAMERA_H
