#ifndef COLLISION_SHAPE_H
#define COLLISION_SHAPE_H

#define GLM_ENABLE_EXPERIMENTAL

#include <glm/glm.hpp>
#include <iostream>
#include "../Loader/modelloader.h"

namespace collision 
{
	struct Triangle {
		glm::vec3 a, b, c;
		Triangle(const glm::vec3& a_, const glm::vec3& b_, const glm::vec3& c_) : a(a_), b(b_), c(c_)
		{}
		Triangle() : a(glm::vec3(0.0)), b(glm::vec3(0.0)), c(glm::vec3(0.0))
		{}

		void Translate(const glm::mat4& model) {
			a = glm::vec3(model * glm::vec4(a, 1.0));
			b = glm::vec3(model * glm::vec4(b, 1.0));
			c = glm::vec3(model * glm::vec4(c, 1.0));
		}
	};

	class Box {
	public:
		Box()
		{}
		Box(const glm::vec3& min, const glm::vec3& max) : m_min(min), m_max(max)
		{
			m_scale = (m_max - m_min) / 2.0f;
			m_position = m_min + m_scale;
		}
		bool Intersect(const Box& box) {
			return ((box.m_min.x <= m_max.x && box.m_max.x >= m_min.x) 
			 	 && (box.m_min.y <= m_max.y && box.m_max.y >= m_min.y)
				 && (box.m_min.z <= m_max.z && box.m_max.z >= m_min.z));
		}
		bool Contains(const glm::vec3 point) {
			return ((point.x >= m_min.x && point.x <= m_max.x) 
				 && (point.y >= m_min.y && point.y <= m_max.y)
				 && (point.z >= m_min.z && point.z <= m_max.z));
		}
	private:
		glm::vec3 m_min, m_max, m_position, m_scale;	
	public:
		const glm::vec3& GetPosition() const { return m_position; }
		const glm::vec3& GetScale() const { return m_scale; }
		const glm::vec3& GetMin() const { return m_min; }
		const glm::vec3& GetMax() const { return m_max; }
		void SetBox(const glm::vec3& position, const glm::vec3& scale) { 
			m_position = position;
			m_scale = scale;
			m_min = m_position - m_scale;
			m_max = m_min + (m_scale * 2.0f);
		}
	};

	inline std::ostream& operator << (std::ostream& os, const Box& box) {
		os << "Box : min : " << box.GetMin().x << " ; " << box.GetMin().y << " ; " << box.GetMin().z << " - max : " << box.GetMax().x << " ; " << box.GetMax().y << " ; " << box.GetMax().z << std::endl;
		return os;
	}

	class CollisionShape 
	{
	public:
		Triangle* triangles;
		int numTriangles;
		CollisionShape(objl::Vertex* vertices, const int& numVertices, GLuint* indices, const int& numIndices);
		CollisionShape(const CollisionShape& obj) : triangles(obj.triangles), numTriangles(obj.numTriangles)
		{}
		CollisionShape() 
		{}
	};

	inline CollisionShape::CollisionShape(objl::Vertex* vertices, const int& numVertices, GLuint* indices, const int& numIndices)
	{
		numTriangles = numIndices / 3;
		triangles = new Triangle[numTriangles];

		int triangleIndex = 0;
		for (int i = 0; i < numIndices; i += 3) {
			int index = i;
			objl::Vector3 a = vertices[indices[index]].Position;
			index++;
			objl::Vector3 b = vertices[indices[index]].Position;
			index++;
			objl::Vector3 c = vertices[indices[index]].Position;

			triangles[triangleIndex] = Triangle(glm::vec3(a.X, a.Y, a.Z), glm::vec3(b.X, b.Y, b.Z), glm::vec3(c.X, c.Y, c.Z));
			triangleIndex++;
		}

		std::cout << " num of triangles : " << numTriangles << std::endl;
		for (int i = 0; i < numTriangles; i++) {
			Triangle t = triangles[i];
			std::cout << "Triangle : a : " << t.a.x << " ; " << t.a.y << " ; " << t.a.z << " - b : " << t.b.x << " ; " << t.b.y << " ; " << t.b.z << " - c : " << t.c.x << " ; " << t.c.y << " ; " << t.c.z << std::endl;
		}
	}
}

#endif //COLLISION_SHAPE_H