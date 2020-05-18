#ifndef COLLIDABLE_OBJECT_H
#define COLLIDABLE_OBJECT_H

#include "ellipsoidbody.h"
#include "../Loader/texture.h"
#include "../Loader/shaderloader.h"

namespace collision
{
	class CollidableObject
	{
	public:
		CollidableObject() {}
		CollidableObject(vaoLoader::VaoObject* model, txtl::Texture2d* texture, shld::ShaderObj* shader);
		~CollidableObject();

		void Update(const std::vector<CollisionObject*>& boundaryList, Terrain* terrain);
		void InitDebugMode(vaoLoader::VaoObject* cubeModel, shld::ShaderObj* debugShader);
		void BindShader();
		void UpdateShader(Camera* camera);
		void Render(Camera* camera);
	private:
		vaoLoader::VaoObject m_vaoObject, m_vaoDebugObject;
		txtl::Texture2d m_texture;
		EllipsoidBody m_ellipsoidBody;
		shld::ShaderObj m_shader, m_shaderDebug;
		bool m_debugMode;

		glm::vec3 m_velocity, m_gravity, m_rotation, m_scale, m_size;
		glm::quat m_quaternion;
		float offsetY;
		glm::mat4 m_model;

		void RenderDebug(Camera* camera);
		void SetModel();
	public:
		void SetVelocity(const glm::vec3& velocity) { m_velocity = velocity; }
		void SetGravity(const glm::vec3& gravity) { m_gravity = gravity; }
		void SetOffsetY(const float& y) { offsetY = y; }
		void Rotate(const glm::vec3& rotation);
		void Scale(const glm::vec3& scale);
		void SetPosition(const glm::vec3& position);
		void SetScale(const glm::vec3& scale);
		void SetRotation(const glm::vec3& rotation);
		void SetDebugMode(const bool& debugMode) { m_debugMode = debugMode; }
		const glm::vec3 GetSize() const { return m_size * m_scale; }
		const glm::vec3& GetVelocity() const { return m_velocity; }
		const glm::vec3& GetGravity() const { return m_gravity; }
		const glm::vec3 GetPosition() const { return m_ellipsoidBody.position; }
		const glm::vec3& GetRotation() const { return m_rotation; }
		const glm::quat& GetQuaternion() const { return m_quaternion; }
		const glm::mat4& GetModel() const { return m_model; }
		const glm::vec3& GetEllipsoidRadius() const { return m_ellipsoidBody.collisionPackage.ellipsoidRadius; }
		const bool& GroundTouched() const { return m_ellipsoidBody.groundTouched; }
		const Box& GetBoundingBox() const { return m_ellipsoidBody.boundingBox; }
		const txtl::Texture2d& GetTexture() const { return m_texture; }
		shld::ShaderObj* GetShader() { return &m_shader; }
	};
}

#endif //COLLIDABLE_OBJECT_H