#include "collidableobject.h"

namespace collision
{
	CollidableObject::CollidableObject(vaoLoader::VaoObject* model, txtl::Texture2d* texture, shld::ShaderObj* shader)
	{
		m_vaoObject = *model;
		m_texture = *texture;
		m_shader = *shader;
		m_scale = glm::vec3(1.0);
		m_size = glm::vec3(0.25, 0.25, 0.25);
		glm::vec3 eRad = glm::vec3(0.8, 1.2, 0.8);
		m_ellipsoidBody = EllipsoidBody(glm::vec3(0, 10, 0), eRad, true);
		m_rotation = glm::vec3(0.0);
		m_gravity = glm::vec3(0.0);
		m_velocity = glm::vec3(0.0);
		offsetY = 0;
		m_quaternion = glm::quat(1.0, 0.0, 0.0, 0.0);
		SetModel();
	}

	CollidableObject::~CollidableObject()
	{

	}

	void CollidableObject::Update(const std::vector<CollisionObject*>& boundaryList, Terrain* terrain)
	{
		m_ellipsoidBody.groundTouched = false;
		//m_ellipsoidBody.CollideWithTerrain(terrain);
		m_ellipsoidBody.CollideAndSlide(m_velocity, m_gravity, boundaryList);

		SetModel();
	}

	void CollidableObject::BindShader()
	{
		glUseProgram(m_shader.programId);
	}

	void CollidableObject::UpdateShader(Camera* camera)
	{
		shld::SetMat4(m_shader, "model", m_model);
		shld::SetMat4(m_shader, "projection", camera->GetProjection());
		shld::SetMat4(m_shader, "view", camera->GetView());
	}

	void CollidableObject::Render(Camera* camera)
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, m_texture.textureId);
		glUseProgram(m_shader.programId);

		glBindVertexArray(m_vaoObject.vaoId);
		glDrawElements(GL_TRIANGLES, m_vaoObject.drawCall, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);

		glDisable(GL_TEXTURE_2D);
		if (m_debugMode) RenderDebug(camera);
	}

	void CollidableObject::InitDebugMode(vaoLoader::VaoObject* cubeModel, shld::ShaderObj* debugShader)
	{
		m_vaoDebugObject = *cubeModel;
		m_shaderDebug = *debugShader;
		m_debugMode = true;
	}

	void CollidableObject::RenderDebug(Camera* camera)
	{
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);	
		glUseProgram(m_shaderDebug.programId);
		glm::mat4 model = glm::mat4(1.0);
		model = glm::translate(model, m_ellipsoidBody.boundingBox.GetPosition());
		model = glm::scale(model, m_ellipsoidBody.boundingBox.GetScale() + 0.05f);
		shld::SetMat4(m_shaderDebug, "model", model);
		shld::SetMat4(m_shaderDebug, "projection", camera->GetProjection());
		shld::SetMat4(m_shaderDebug, "view", camera->GetView());
		glBindVertexArray(m_vaoDebugObject.vaoId);
		glDrawElements(GL_TRIANGLES, m_vaoDebugObject.drawCall, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
		glDisable(GL_BLEND);
	}

	void CollidableObject::SetModel()
	{
		glm::vec3 position = m_ellipsoidBody.position / m_ellipsoidBody.collisionPackage.ellipsoidRadius;
		position.y -= m_ellipsoidBody.boundingBox.GetScale().y - offsetY;
		m_model = glm::mat4(1.0);
		m_model = glm::translate(m_model, position);
		m_model = glm::scale(m_model, m_size * m_scale);
		m_quaternion = glm::quat(glm::radians(m_rotation));
		m_model *= glm::toMat4(m_quaternion);
	}

	void CollidableObject::SetPosition(const glm::vec3 &position)
	{
		m_ellipsoidBody.position = position;
		SetModel();
	}

	void CollidableObject::SetScale(const glm::vec3& scale)
	{
		m_scale = scale;
		m_ellipsoidBody.collisionPackage.scale = m_scale;
		SetModel();
	}

	void CollidableObject::SetRotation(const glm::vec3 &rotation)
	{
		m_rotation = rotation;
		if (m_rotation.x < 0) m_rotation.x += 360;
		else if (m_rotation.x > 360) m_rotation.x -= 360;
		if (m_rotation.y < 0) m_rotation.y += 360;
		else if (m_rotation.y > 360) m_rotation.y -= 360;
		if (m_rotation.z < 0) m_rotation.z += 360;
		else if (m_rotation.z > 360) m_rotation.z -= 360;
		SetModel();
	}

	void CollidableObject::Rotate(const glm::vec3& rotation)
	{
		m_rotation += rotation;
		if (m_rotation.x < 0) m_rotation.x += 360;
		else if (m_rotation.x > 360) m_rotation.x -= 360;
		if (m_rotation.y < 0) m_rotation.y += 360;
		else if (m_rotation.y > 360) m_rotation.y -= 360;
		if (m_rotation.z < 0) m_rotation.z += 360;
		else if (m_rotation.z > 360) m_rotation.z -= 360;
		SetModel();
	}

	void CollidableObject::Scale(const glm::vec3& scale)
	{
		m_scale *= scale;
		m_ellipsoidBody.collisionPackage.scale = m_scale;
		SetModel();
	}
}