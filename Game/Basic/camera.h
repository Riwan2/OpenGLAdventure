#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Camera
{
public:
    Camera();
    ~Camera();
    
    void SetTarget(const glm::vec3 target);
    void Zoom(const float& amount);
    void Rotate(const float& angleY, const float& angleX); 
    const glm::mat4& getView();
private:
    glm::mat4 m_view;
    
    glm::vec3 m_position;
    glm::vec3 m_target;
    glm::vec3 m_front;
    glm::vec3 m_up;
    
    float m_angleAround;
    float m_yaw;
    float m_pitch;
    float m_distance;
};

#endif // CAMERA_H
