#ifndef ELLIPSOID_BODY_H
#define ELLIPSOID_BODY_H

#include "collision.h"
#include "collisionobject.h"

namespace collision
{
	class EllipsoidBody {
	public:
		CollisionPackage collisionPackage;
		Box boundingBox;
		glm::vec3 position, rotated_point;
		float collisionRecursionDepth, veryCloseDistance;
		bool collideWithObject, objectCollided, groundTouched;

		EllipsoidBody();
		EllipsoidBody(const glm::vec3& pos, const glm::vec3& eRad, const bool& objectCollide = false);
		EllipsoidBody(const glm::vec3& pos, const glm::vec3& min, const glm::vec3& max, const bool& objectCollide = false);
		EllipsoidBody(const EllipsoidBody& obj);
		~EllipsoidBody();
		
		void CollideWithTerrain(Terrain* terrain);
		void CollideAndSlide(const glm::vec3& velocity, const glm::vec3& gravity, const std::vector<CollisionObject*> boundaryList);
		glm::vec3 CollideWithWorld(glm::vec3& position, glm::vec3& velocity, const std::vector<CollisionObject*> boundaryList);
	};
}

#endif //ELLIPSOID_BODY_H