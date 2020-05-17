#include "ellipsoidbody.h"

namespace collision {
	EllipsoidBody::EllipsoidBody()
	{
	}

	EllipsoidBody::EllipsoidBody(const glm::vec3& pos, const glm::vec3& eRad, const bool& objectCollide)
	{
		veryCloseDistance = 0.025f;
		position = pos;
		collisionPackage = CollisionPackage(eRad);
		collisionRecursionDepth = 0;
		groundTouched = false;

		boundingBox = Box(glm::vec3(0 - eRad.x, 0 - eRad.y, 0 - eRad.z), glm::vec3(0 + eRad.x, 0 + eRad.y, 0 + eRad.z));
		collideWithObject = objectCollide;
	}

	EllipsoidBody::EllipsoidBody(const glm::vec3& pos, const glm::vec3& min, const glm::vec3& max, const bool& objectCollide)
	{
		veryCloseDistance = 0.025f;
		position = pos;
		collisionPackage = CollisionPackage((max - min) / 2.0f);
		collisionRecursionDepth = 0;
		groundTouched = false;

		boundingBox = Box(min, max);
		collideWithObject = objectCollide;
	}

	EllipsoidBody::EllipsoidBody(const EllipsoidBody& obj)
	{
		veryCloseDistance = obj.veryCloseDistance;
		collisionPackage = obj.collisionPackage;
		position = obj.position;
		collisionRecursionDepth = 0;
		groundTouched = false;
		boundingBox = obj.boundingBox;
		collideWithObject = obj.collideWithObject;
	}

	EllipsoidBody::~EllipsoidBody()
	{

	}

	void EllipsoidBody::CollideWithTerrain(Terrain* terrain)
	{
		//Terrain collision
		glm::vec3 pos = position / collisionPackage.ellipsoidRadius;
		float terrainHeight = terrain->GetMapHeight(pos.x, pos.z) + boundingBox.GetScale().y + 0.2;
		if (pos.y < terrainHeight) {
			pos.y = terrainHeight;
			position.y = pos.y * collisionPackage.ellipsoidRadius.y;
			groundTouched = true;
		}
	}

	void EllipsoidBody::CollideAndSlide(const glm::vec3& velocity, const glm::vec3& gravity, const std::vector<CollisionObject*> boundaryList) 
	{
		if (collideWithObject) {
			for (int a = 0; a < boundaryList.size(); a++) {
				if (boundingBox.Intersect(boundaryList[a]->GetBoundingBox())) {
					position += boundaryList[a]->GetVelocity();
					position = boundaryList[a]->GetPosition() + boundaryList[a]->GetQuaternionVelocity() * (position - boundaryList[a]->GetPosition());
				}
			} 
		}		

		collisionPackage.R3Position = position;
		collisionPackage.R3Velocity = velocity;

		collisionPackage.ellipsoidRadius = collisionPackage.baseRadius * collisionPackage.scale;
		glm::vec3 squaredRadius = collisionPackage.ellipsoidRadius * collisionPackage.ellipsoidRadius;
		glm::vec3 eSpacePosition = collisionPackage.R3Position / squaredRadius;
		glm::vec3 eSpaceVelocity = collisionPackage.R3Velocity / collisionPackage.ellipsoidRadius;

		collisionRecursionDepth = 0;

		glm::vec3 finalPosition = CollideWithWorld(eSpacePosition, eSpaceVelocity, boundaryList);

		collisionPackage.R3Position = finalPosition * squaredRadius;
		collisionPackage.R3Velocity = gravity;
		eSpaceVelocity = collisionPackage.R3Velocity / collisionPackage.ellipsoidRadius;
		collisionRecursionDepth = 0;

		finalPosition = CollideWithWorld(finalPosition, eSpaceVelocity, boundaryList);

		boundingBox.SetBox(finalPosition * collisionPackage.ellipsoidRadius, collisionPackage.ellipsoidRadius + 0.1f);
		finalPosition = finalPosition * collisionPackage.ellipsoidRadius;

		position = finalPosition * collisionPackage.ellipsoidRadius;
	}

	glm::vec3 EllipsoidBody::CollideWithWorld(glm::vec3& position, glm::vec3& velocity, const std::vector<CollisionObject*> boundaryList)
	{
		float finaleVeryCloseDistance = veryCloseDistance / collisionPackage.scale.y;

		if (collisionRecursionDepth > 2)
			return position;

		collisionPackage.velocity = velocity;
		collisionPackage.basePoint = position;
		collisionPackage.foundCollision = false;
		if (velocity != glm::vec3(0.0)) collisionPackage.normalizedVelocity = glm::normalize(velocity);

		//Check collision
		//Object
		if (collideWithObject) {
			for (int a = 0; a < boundaryList.size(); a++) {
				if (boundingBox.Intersect(boundaryList[a]->GetBoundingBox())) {
					for (int i = 0; i < boundaryList[a]->GetCollisionShape().numTriangles; i++) {
						Triangle t = boundaryList[a]->GetCollisionShape().triangles[i];
						t.Translate(boundaryList[a]->GetModel());
						t.a /= collisionPackage.ellipsoidRadius;
						t.b /= collisionPackage.ellipsoidRadius;
						t.c /= collisionPackage.ellipsoidRadius;
						CheckTriangleCollision(&collisionPackage, t.a, t.b, t.c);
					}
				}
			}
		} 

		if (!collisionPackage.foundCollision) {
			return position + velocity;
		}

		glm::vec3 destinationPoint = position + velocity;
		glm::vec3 newBasePoint = position;

		if (collisionPackage.nearestDistance >= finaleVeryCloseDistance) {
			glm::vec3 V;
			V = collisionPackage.normalizedVelocity;
			V = V * (float)(collisionPackage.nearestDistance - finaleVeryCloseDistance);
			newBasePoint = collisionPackage.basePoint + V;

			if (V != glm::vec3(0.0)) V = glm::normalize(V);
			collisionPackage.intersectPoint -= finaleVeryCloseDistance * V;
		}

		glm::vec3 slidePlaneOrigin = collisionPackage.intersectPoint;
		glm::vec3 slidePlaneNormal = newBasePoint - collisionPackage.intersectPoint;
		
		//Ground ???
		if (slidePlaneNormal.y > 0.8 && slidePlaneNormal.y < 2.0)
			groundTouched = true;

		if (slidePlaneNormal != glm::vec3(0.0)) slidePlaneNormal = glm::normalize(slidePlaneNormal);
		Plane slidingPlane(slidePlaneOrigin, slidePlaneNormal);

		glm::vec3 newDestinationPoint = destinationPoint - (float)slidingPlane.SignedDistanceTo(destinationPoint) * slidePlaneNormal;
		glm::vec3 newVelocityVector = newDestinationPoint - collisionPackage.intersectPoint;

		if (glm::length(newVelocityVector) < finaleVeryCloseDistance) {
			return newBasePoint;
		}

		collisionRecursionDepth++;
		return CollideWithWorld(newBasePoint, newVelocityVector, boundaryList);
	}
}