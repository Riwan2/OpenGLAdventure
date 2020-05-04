#ifndef SKYBOX_H
#define SKYBOX_H

#include "../Loader/modelloader.h"
#include "../Model/shader.h"
#include "../Basic/camera.h"
#include "../Loader/texture.h"

class Skybox
{
public:
	Skybox(const shld::ShaderObj& shaderObj, const std::vector<std::string> facesFileName, const float& size);
	~Skybox();
	void Render(const Camera& camera, const glm::vec3& playerPos);
private:
	Shader* m_shader;
	vaoLoader::VaoObject m_vaoObject;
	GLuint m_textureId;
};

#endif //SKYBOX