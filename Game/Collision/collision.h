#ifndef COLLISION_H
#define COLLISION_H

#define GLM_ENABLE_EXPERIMENTAL

#include <glm/glm.hpp>
#include <glm/gtx/norm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include "../Loader/modelloader.h"

namespace collision 
{
	//Plane :
	class Plane {
	public:
		float equation[4];
		glm::vec3 origin;
		glm::vec3 normal;

		Plane(const glm::vec3& origin_, const glm::vec3& normal_);
		Plane(const glm::vec3& p1, const glm::vec3& p2, const glm::vec3& p3);
		bool IsFrontFacingTo(const glm::vec3& direction);
		double SignedDistanceTo(const glm::vec3& point);
	};

	inline Plane::Plane(const glm::vec3& origin_, const glm::vec3& normal_)
	{
		normal = normal_;
		origin = origin_;
		equation[0] = normal.x;
		equation[1] = normal.y;
		equation[2] = normal.z;
		equation[3] = -(normal.x * origin.x + normal.y * origin.y + normal.z * origin.z);
	}

	inline Plane::Plane(const glm::vec3& p1, const glm::vec3& p2, const glm::vec3& p3)
	{
		normal = glm::cross(p2 - p1, p3 - p1);
		if (normal != glm::vec3(0.0)) normal = glm::normalize(normal);
		origin = p1;
		equation[0] = normal.x;
		equation[1] = normal.y;
		equation[2] = normal.z;
		equation[3] = -(normal.x * origin.x + normal.y * origin.y + normal.z * origin.z);
	}

	inline bool Plane::IsFrontFacingTo(const glm::vec3 &direction)
	{
		double dot = glm::dot(normal, direction);
		return (dot <= 0);
	}

	inline double Plane::SignedDistanceTo(const glm::vec3& point)
	{
		return glm::dot(point, normal) + equation[3];
	}

	//Ellipsoid Collision Object : 
	struct CollisionObject {
		glm::vec3 ellipsoidRadius;
		// R3
		glm::vec3 R3Velocity;
		glm::vec3 R3Position;
		// eSpace
		glm::vec3 velocity;
		glm::vec3 normalizedVelocity;
		glm::vec3 basePoint;
		// Collision info
		bool foundCollision;
		double nearestDistance;
		glm::vec3 intersectPoint;

		CollisionObject(const glm::vec3& eRad) : ellipsoidRadius(eRad)
		{}
	};

	//Collision
	inline bool CheckPointInTriangle(const glm::vec3& p, const glm::vec3& a, const glm::vec3& b, const glm::vec3& c)
	{
		glm::vec3 v0 = c - a;
		glm::vec3 v1 = b - a;
		glm::vec3 v2 = p - a;

		float dot00 = glm::dot(v0, v0);
		float dot01 = glm::dot(v0, v1);
		float dot02 = glm::dot(v0, v2);
		float dot11 = glm::dot(v1, v1);
		float dot12 = glm::dot(v1, v2);

		float invDenom = 1 / (dot00 * dot11 - dot01 * dot01);
		float u = (dot11 * dot02 - dot01 * dot12) * invDenom;
		float v = (dot00 * dot12 - dot01 * dot02) * invDenom;

		return (u >= 0.0f) && (v >= 0.0f) && (u + v < 1.0f);
	}

	inline bool GetLowestRoot(float a, float b, float c, float maxR, float* root) 
	{
		float determinant = b * b - 4.0f * a * c;
		if (determinant < 0.0f) return false;
		float sqrtD = sqrt(determinant);
		float r1 = (-b - sqrtD) / (2.0f * a);
		float r2 = (-b + sqrtD) / (2.0f * a);
		if (r1 > r2) {
			float temp = r2;
			r2 = r1;
			r1 = temp;
		}
		if (r1 > 0.0f && r1 < maxR) {
			*root = r1;
			return true;
		}
		if (r2 > 0.0f && r2 < maxR) {
			*root = r2;
			return true;
		}
		return false;
	}

	//Check Triangle Collision
	inline void CheckTriangleCollision(CollisionObject* object, const glm::vec3& p1, const glm::vec3& p2, const glm::vec3& p3)
	{
		Plane trianglePlane(p1, p2, p3);

		if (trianglePlane.IsFrontFacingTo(object->normalizedVelocity)) {
			double t0, t1;
			bool embeddedInPlane = false;

			double signedDistanceToTrianglePlane = trianglePlane.SignedDistanceTo(object->basePoint);
			float normalDotVelocity = glm::dot(trianglePlane.normal, object->velocity);

			if (normalDotVelocity == 0.0f) {
				if (abs(signedDistanceToTrianglePlane) >= 1.0f) {
					return; //Sphere not embeded in plane, no collision
				} else {
					embeddedInPlane = true; //Sphere embeded in plane
					t0 = 0.0f;
					t1 = 1.0f;
				}
			} else {
				t0 = (-1.0f - signedDistanceToTrianglePlane) / normalDotVelocity;
				t1 = (1.0f - signedDistanceToTrianglePlane) / normalDotVelocity;

				if (t0 > t1) {
					double temp = t1;
					t1 = t0;
					t0 = temp;
				}

				if (t0 > 1.0f || t1 < 0.0f) {
					return; //t value outside [0, 1], no collision
				}

				if (t0 < 0.0f) t0 = 0.0f; //Clamp to [0, 1]
				if (t1 < 0.0f) t1 = 0.0f;
				if (t0 > 1.0f) t0 = 1.0f;
				if (t1 > 1.0f) t1 = 1.0f;
			}

			glm::vec3 collisionPoint;
			bool foundCollision = false;
			float t = 1.0f;

			if (!embeddedInPlane) {
				glm::vec3 planeIntersectionPoint = (object->basePoint - trianglePlane.normal) + (float)t0 * object->velocity;
				if (CheckPointInTriangle(planeIntersectionPoint, p1, p2, p3)) {
					foundCollision = true;
					t = t0;
					collisionPoint = planeIntersectionPoint;
				}
			}

			if (!foundCollision) {
				glm::vec3 velocity = object->velocity;
				glm::vec3 base = object->basePoint;
				float velocitySquaredLenght = glm::length2(velocity);
				float a, b, c;
				float newT;
				a = velocitySquaredLenght;
				//P1
				b = 2.0f * (glm::dot(velocity, base - p1));
				c = glm::length2(p1 - base) - 1.0f;
				if (GetLowestRoot(a, b, c, t, &newT)) {
					t = newT;
					foundCollision = true;
					collisionPoint = p1;
				}
				//P2
				b = 2.0f * (glm::dot(velocity, base - p2));
				c = glm::length2(p2 - base) - 1.0f;
				if (GetLowestRoot(a, b, c, t, &newT)) {
					t = newT;
					foundCollision = true;
					collisionPoint = p2;
				}
				//P3
				b = 2.0f * (glm::dot(velocity, base - p3));
				c = glm::length2(p3 - base) - 1.0f;
				if (GetLowestRoot(a, b, c, t, &newT)) {
					t = newT;
					foundCollision = true;
					collisionPoint = p3;
				}

				//Check Edge
				//P1 -> P2
				glm::vec3 edge = p2 - p1;
				glm::vec3 baseToVertex = p1 - base;
				float edgeSquaredLength = glm::length2(edge);
				float edgeDotVelocity = glm::dot(edge, velocity);
				float edgeDotBaseToVertex = glm::dot(edge, baseToVertex);

				a = edgeSquaredLength * -velocitySquaredLenght + edgeDotVelocity * edgeDotVelocity;
				b = edgeSquaredLength * (2 * glm::dot(velocity, baseToVertex)) - 2.0 * edgeDotVelocity * edgeDotBaseToVertex;
				c = edgeSquaredLength * (1 - glm::length2(baseToVertex)) + edgeDotBaseToVertex * edgeDotBaseToVertex;

				if (GetLowestRoot(a, b, c, t, &newT)) {
					float f = (edgeDotVelocity * newT - edgeDotBaseToVertex) / edgeSquaredLength;
					if (f >= 0.0f && f <= 1.0f) {
						t = newT;
						foundCollision = true;
						collisionPoint = p1 + f * edge;
					}
				}

				//P2 -> P3
				edge = p3 - p2;
				baseToVertex = p2 - base;
				edgeSquaredLength = glm::length2(edge);
				edgeDotVelocity = glm::dot(edge, velocity);
				edgeDotBaseToVertex = glm::dot(edge, baseToVertex);

				a = edgeSquaredLength * -velocitySquaredLenght + edgeDotVelocity * edgeDotVelocity;
				b = edgeSquaredLength * (2 * glm::dot(velocity, baseToVertex)) - 2.0 * edgeDotVelocity * edgeDotBaseToVertex;
				c = edgeSquaredLength * (1 - glm::length2(baseToVertex)) + edgeDotBaseToVertex * edgeDotBaseToVertex;

				if (GetLowestRoot(a, b, c, t, &newT)) {
					float f = (edgeDotVelocity * newT - edgeDotBaseToVertex) / edgeSquaredLength;
					if (f >= 0.0f && f <= 1.0f) {
						t = newT;
						foundCollision = true;
						collisionPoint = p2 + f * edge;
					}
				}

				//P3 -> P1
				edge = p1 - p3;
				baseToVertex = p3 - base;
				edgeSquaredLength = glm::length2(edge);
				edgeDotVelocity = glm::dot(edge, velocity);
				edgeDotBaseToVertex = glm::dot(edge, baseToVertex);

				a = edgeSquaredLength * -velocitySquaredLenght + edgeDotVelocity * edgeDotVelocity;
				b = edgeSquaredLength * (2 * glm::dot(velocity, baseToVertex)) - 2.0 * edgeDotVelocity * edgeDotBaseToVertex;
				c = edgeSquaredLength * (1 - glm::length2(baseToVertex)) + edgeDotBaseToVertex * edgeDotBaseToVertex;

				if (GetLowestRoot(a, b, c, t, &newT)) {
					float f = (edgeDotVelocity * newT - edgeDotBaseToVertex) / edgeSquaredLength;
					if (f >= 0.0f && f <= 1.0f) {
						t = newT;
						foundCollision = true;
						collisionPoint = p3 + f * edge;
					}
				}
			}
			
			if (foundCollision) {
				float distToCollision = t * glm::length(object->velocity);
				if (object->foundCollision == false || distToCollision < object->nearestDistance) {
					object->nearestDistance = distToCollision;
					object->intersectPoint = collisionPoint;
					object->foundCollision = true;
				}
			}
		}
	}

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

	class CollisionShape 
	{
	public:
		Triangle* triangles;
		int numTriangles;
		CollisionShape(objl::Vertex* vertices, const int& numVertices, GLuint* indices, const int& numIndices);
		CollisionShape(const CollisionShape& obj) : triangles(obj.triangles), numTriangles(obj.numTriangles)
		{}
		void Translate(const glm::mat4& model);
	};

	inline CollisionShape::CollisionShape(objl::Vertex* vertices, const int& numVertices, GLuint* indices, const int& numIndices)
	{
		numTriangles = numIndices / 3;
		triangles = new Triangle[numTriangles];

		std::cout << vertices << std::endl;

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

	inline void CollisionShape::Translate(const glm::mat4& model)
	{
		for (int i = 0; i < numTriangles; i++) {
			triangles[i].Translate(model);
		}
	}

	class CollisionEntity {
	public:
		CollisionObject collisionObject;
		glm::vec3 position;
		float collisionRecursionDepth;

		CollisionEntity(const CollisionEntity& obj) : collisionObject(obj.collisionObject), position(obj.position), collisionRecursionDepth(0)
		{}
		CollisionEntity(const glm::vec3& pos, const glm::vec3 eRad) : position(pos), collisionObject(eRad), collisionRecursionDepth(0)
		{}
		void CollideAndSlide(const glm::vec3& velocity, const glm::vec3& gravity, const std::vector<CollisionShape*> boundaryList);
		glm::vec3 CollideWithWorld(const glm::vec3& position, const glm::vec3& velocity, const std::vector<CollisionShape*> boundaryList);
	};

	inline void CollisionEntity::CollideAndSlide(const glm::vec3& velocity, const glm::vec3& gravity, const std::vector<CollisionShape*> boundaryList) 
	{
		collisionObject.R3Position = position;
		collisionObject.R3Velocity = velocity;

		glm::vec3 eSpacePosition = collisionObject.R3Position / (collisionObject.ellipsoidRadius * 1.0f);
		glm::vec3 eSpaceVelocity = collisionObject.R3Velocity / collisionObject.ellipsoidRadius;

		collisionRecursionDepth = 0;

		glm::vec3 finalPosition = CollideWithWorld(eSpacePosition, eSpaceVelocity, boundaryList);

		collisionObject.R3Position = finalPosition * collisionObject.ellipsoidRadius;
		collisionObject.R3Velocity = gravity;
		eSpaceVelocity = gravity / collisionObject.ellipsoidRadius;
		collisionRecursionDepth = 0;

		finalPosition = CollideWithWorld(finalPosition, eSpaceVelocity, boundaryList);

		finalPosition = finalPosition * collisionObject.ellipsoidRadius;
		position = finalPosition;
	}

	const float unitPerMeter = 100.0f;

	inline glm::vec3 CollisionEntity::CollideWithWorld(const glm::vec3& position, const glm::vec3& velocity, const std::vector<CollisionShape*> boundaryList)
	{
		float unitScale = unitPerMeter / 100.0f;
		float veryCloseDistance = 0.05f * unitScale;

		if (collisionRecursionDepth > 5)
			return position;

		collisionObject.velocity = velocity;
		if (velocity != glm::vec3(0.0)) collisionObject.normalizedVelocity = glm::normalize(velocity);
		collisionObject.basePoint = position;
		collisionObject.foundCollision = false;

		//Check collision
		for (int a = 0; a < boundaryList.size(); a++) {
			for (int i = 0; i < boundaryList[a]->numTriangles; i++) {
				Triangle t = boundaryList[a]->triangles[i];
				CheckTriangleCollision(&collisionObject, t.a, t.b, t.c);
			}
		}	

		if (!collisionObject.foundCollision)
			return position + velocity;

		glm::vec3 destinationPoint = position + velocity;
		glm::vec3 newBasePoint = position;

		if (collisionObject.nearestDistance >= veryCloseDistance) {
			glm::vec3 V;
			if (velocity != glm::vec3(0.0)) V = glm::normalize(velocity);
			V = V * (float)(collisionObject.nearestDistance - veryCloseDistance);
			newBasePoint = collisionObject.basePoint + V;

			if (V != glm::vec3(0.0)) V = glm::normalize(V);
			collisionObject.intersectPoint -= veryCloseDistance * V;
		}

		glm::vec3 slidePlaneOrigin = collisionObject.intersectPoint;
		glm::vec3 slidePlaneNormal = newBasePoint - collisionObject.intersectPoint;
		if (slidePlaneNormal != glm::vec3(0.0)) slidePlaneNormal = glm::normalize(slidePlaneNormal);
		Plane slidingPlane(slidePlaneOrigin, slidePlaneNormal);

		glm::vec3 newDestinationPoint = destinationPoint - (float)slidingPlane.SignedDistanceTo(destinationPoint) * slidePlaneNormal;
		glm::vec3 newVelocityVector = newDestinationPoint - collisionObject.intersectPoint;

		if (glm::length(newVelocityVector) < veryCloseDistance) {
			return newBasePoint;
		}

		collisionRecursionDepth++;
		return CollideWithWorld(newBasePoint, newVelocityVector, boundaryList);
	}
}

#endif //COLLISION_H