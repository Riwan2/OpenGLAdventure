#include "collisionobject.h"

namespace collision 
{
	CollisionObject::CollisionObject(vaoLoader::VaoObject* model, vaoLoader::VaoObject* collisionShape, txtl::Texture2d* texture, shld::ShaderObj* shader)
	{
		m_vaoObject = *model;
		m_texture = *texture;
		m_collisionShape = CollisionShape(collisionShape->vertices, collisionShape->numVertices, collisionShape->indices, collisionShape->numIndices);
		m_shader = *shader;
		m_boundingBox = Box(collisionShape->min, collisionShape->max);

		m_debugMode = false;
		m_position = glm::vec3(0.0);
		m_scale = glm::vec3(1.0);
		m_rotation = glm::vec3(0.0);
		SetModel();
	}

	CollisionObject::~CollisionObject()
	{

	}

	void CollisionObject::Render(Camera* camera)
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, m_texture.textureId);
		glUseProgram(m_shader.programId);
		ShaderUpdate(camera);		

		glBindVertexArray(m_vaoObject.vaoId);
		glDrawElements(GL_TRIANGLES, m_vaoObject.drawCall, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);

		glDisable(GL_TEXTURE_2D);
		if (m_debugMode) RenderDebug(camera);
	}

	void CollisionObject::InitDebugMode(vaoLoader::VaoObject* cubeModel, shld::ShaderObj* debugShader)
	{
		m_vaoDebugObject = *cubeModel;
		m_shaderDebug = *debugShader;
		m_debugMode = true;
	}

	void CollisionObject::RenderDebug(Camera* camera)
	{
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);	
		glUseProgram(m_shaderDebug.programId);
		glm::mat4 model = glm::mat4(1.0);
		model = glm::translate(model, m_boundingBox.GetPosition());
		model = glm::scale(model, m_boundingBox.GetScale() + 0.05f);
		shld::SetMat4(m_shaderDebug, "model", model);
		shld::SetMat4(m_shaderDebug, "projection", camera->GetProjection());
		shld::SetMat4(m_shaderDebug, "view", camera->GetView());
		glBindVertexArray(m_vaoDebugObject.vaoId);
		glDrawElements(GL_TRIANGLES, m_vaoDebugObject.drawCall, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
		glDisable(GL_BLEND);
	}

	void CollisionObject::ShaderUpdate(Camera* camera)
	{
		shld::SetMat4(m_shader, "model", m_model);
		shld::SetMat4(m_shader, "projection", camera->GetProjection());
		shld::SetMat4(m_shader, "view", camera->GetView());
	}

	void CollisionObject::SetModel()
	{
		m_model = glm::mat4(1.0);
		m_model = glm::translate(m_model, m_position);
		m_model = glm::scale(m_model, m_scale);
		m_model = glm::rotate(m_model, (float)glm::radians(m_rotation.x), glm::vec3(1, 0, 0));
		m_model = glm::rotate(m_model, (float)glm::radians(m_rotation.y), glm::vec3(0, 1, 0));
		m_model = glm::rotate(m_model, (float)glm::radians(m_rotation.z), glm::vec3(0, 0, 1));
	}

	void CollisionObject::SetPosition(const glm::vec3& position) { 
		m_position = position; 
		SetModel();
	}

	void CollisionObject::SetRotation(const glm::vec3& rotation) { 
		m_rotation = rotation; 
		SetModel();
	}

	void CollisionObject::SetScale(const glm::vec3& scale) { 
		m_scale = scale; 
		SetModel();
	}

	void CollisionObject::Move(const glm::vec3& position) {
		m_position += position;
		SetModel();
	}

	void CollisionObject::Rotate(const glm::vec3& rotation) {
		m_rotation += rotation;
		if (m_rotation.x < 0) m_rotation.x += 360;
		else if (m_rotation.x > 360) m_rotation.x -= 360;
		if (m_rotation.y < 0) m_rotation.x += 360;
		else if (m_rotation.y > 360) m_rotation.x -= 360;
		if (m_rotation.z < 0) m_rotation.x += 360;
		else if (m_rotation.z > 360) m_rotation.x -= 360;
		SetModel();
	}

	void CollisionObject::Scale(const glm::vec3& scale) {
		m_scale *= scale;
		SetModel();
	}
}