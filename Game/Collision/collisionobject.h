#ifndef COLLISION_OBJECT_H
#define COLLISION_OBJECT_H

#include "collisionshape.h"
#include "../Loader/texture.h"
#include "../Loader/shaderloader.h"
#include "../Basic/camera.h"

namespace collision
{
	class CollisionObject 
	{
	public:
		CollisionObject(vaoLoader::VaoObject* model, vaoLoader::VaoObject* collisionShape, txtl::Texture2d* texture, shld::ShaderObj* shader);
		~CollisionObject();

		void InitDebugMode(vaoLoader::VaoObject* cubeModel, shld::ShaderObj* debugShader);
		void Render(Camera* camera);
		void ShaderUpdate(Camera* camera);
	private:
		bool m_debugMode;
		vaoLoader::VaoObject m_vaoObject, m_vaoDebugObject;
		CollisionShape m_collisionShape;
		txtl::Texture2d m_texture;
		Box m_boundingBox;
		
		shld::ShaderObj m_shader, m_shaderDebug;

		glm::vec3 m_position, m_rotation, m_scale; 
		glm::mat4 m_model;

		void SetModel();
		void RenderDebug(Camera* camera);
	public:
		void Move(const glm::vec3& position);
		void Rotate(const glm::vec3& rotation);
		void Scale(const glm::vec3& scale);
		void SetPosition(const glm::vec3& position);
		void SetRotation(const glm::vec3& rotation);
		void SetScale(const glm::vec3& scale);
		const glm::vec3& GetPosition() const { return m_position; }
		const glm::vec3& GetRotation() const { return m_rotation; }
		const glm::vec3& GetScale() const { return m_scale; }
		const glm::mat4 GetModel() const { return m_model; }
		const CollisionShape& GetCollisionShape() const { return m_collisionShape; }
		const Box& GetBoundingBox() const { return m_boundingBox; }
	};
}

#endif //COLLISION_OBJECT_H
