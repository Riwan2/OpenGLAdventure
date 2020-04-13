#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Camera
{
public:
    Camera(const float& distance);
    ~Camera();
    
    void SetTarget(const glm::vec3 target);
    void Zoom(const float& amount);
    void Rotate(const float& angleY, const float& angleX);
    
private:
    glm::mat4 m_view, m_projection;
    glm::vec3 m_position, m_target, m_front, m_up;
    float m_angleAround, m_yaw, m_pitch, m_distance;
    
    void CalculateView();
    
public:
    const glm::mat4& GetView() const { return m_view; }
    const glm::mat4& GetProjection() const { return m_projection; }
    const float& GetAngleAround() const { return m_angleAround; }
};

#endif // CAMERA_H
