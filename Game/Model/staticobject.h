#ifndef STATIC_OBJECT_H
#define STATIC_OBJECT_H

#include "simpleobject.h"

namespace stl
{
	struct Box {
		float widthX, widthZ, height;
		glm::vec3 position;
		Box(glm::vec3 pos, float wX, float wZ, float h) : position(pos), widthX(wX), widthZ(wZ), height(h) 
		{}
		Box(const Box& box) : position(box.position), widthX(box.widthX), widthZ(box.widthZ), height(box.height)
		{}
		Box() : position(glm::vec3(0.0)), widthX(0), widthZ(0), height(0)
		{}
		Box(spl::SimpleObject obj) : position(obj.position), widthX(obj.scale.x), widthZ(obj.scale.y), height(obj.scale.z)
		{}

		bool IntersectRight(const Box& b, const float& offset = 0) {
			return (b.position.x - b.widthX / 2 <= position.x + widthX / 2 + offset
				&& b.position.x - b.widthX / 2 >= position.x - widthX / 2
				&& b.position.z - b.widthZ / 2 <= position.z + widthZ / 2 
				&& b.position.z + b.widthZ / 2 >= position.z - widthZ / 2
				&& b.position.y - b.height / 2 <= position.y + height / 2
				&& b.position.y + b.height / 2 >= position.y - height / 2);
		}
		bool IntersectLeft(const Box& b, const float& offset = 0) {
			return (b.position.x + b.widthX / 2 >= position.x - widthX / 2 + offset
				&& b.position.x + b.widthX / 2 <= position.x + widthX / 2
				&& b.position.z - b.widthZ / 2 <= position.z + widthZ / 2
				&& b.position.z + b.widthZ / 2 >= position.z - widthZ / 2  
				&& b.position.y - b.height / 2 <= position.y + height / 2 
				&& b.position.y + b.height / 2 >= position.y - height / 2);
		}
		bool IntersectTop(const Box& b, const float& offset = 0) {
			return (b.position.z + b.widthZ / 2 >= position.z - widthZ / 2 + offset
				&& b.position.z - b.widthZ / 2 <= position.z - widthZ / 2
				&& b.position.x - b.widthX / 2 <= position.x + widthX / 2 
				&& b.position.x + b.widthX / 2 >= position.x - widthX / 2
				&& b.position.y - b.height / 2 <= position.y + height / 2 
				&& b.position.y + b.height / 2 >= position.y - height / 2);
		}
		bool IntersectBot(const Box& b, const float& offset = 0) {
			return (b.position.z - b.widthZ / 2 <= position.z + widthZ / 2 + offset
				&& b.position.z + b.widthZ / 2 >= position.z + b.widthZ / 2
				&& b.position.x - b.widthX / 2 <= position.x + widthX / 2 
				&& b.position.x + b.widthX / 2 >= position.x - widthX / 2
				&& b.position.y - b.height / 2 <= position.y + height / 2 
				&& b.position.y + b.height / 2 >= position.y - height / 2);
		}
		bool IntersectUp(const Box& b, const float& offset = 0) {
			return (b.position.y - b.height <= position.y + height + abs(offset)
				&& b.position.y + b.height >= position.y + height
				&& b.position.x - b.widthX <= position.x + widthX
				&& b.position.x + b.widthX >= position.x - widthX
				&& b.position.z - b.widthZ <= position.z + widthZ
				&& b.position.z + b.widthZ >= position.z - widthZ);
		}
		bool IntersectDown(const Box& b, const float& offset = 0) {
			return (b.position.y + b.height >= position.y - height - abs(offset)
				&& b.position.y - b.height <= position.y - height
				&& b.position.x - b.widthX <= position.x + widthX
				&& b.position.x + b.widthX >= position.x - widthX
				&& b.position.z - b.widthZ <= position.z + widthZ
				&& b.position.z + b.widthZ >= position.z - widthZ);
		}
	};

	struct StaticObject {
		spl::SimpleObject simpleObject;
		Box box;
		StaticObject(const spl::SimpleObject& obj, const Box& b) : simpleObject(obj), box(obj)
		{}
		StaticObject(const vaoLoader::VaoObject& obj, const txtl::Texture2d& tex, GLuint sId) : simpleObject(obj, tex, sId), box(simpleObject)
		{}
	};

	inline void SetModel(StaticObject& object, const glm::vec3& position, const glm::vec3& scale = glm::vec3(1.0), const float& rotX = 0.0, const float& rotY = 0.0, const float& rotZ = 0.0)
	{
		spl::SetModel(object.simpleObject, position, scale, rotX, rotY, rotZ);
		object.box.widthX = scale.x;
		object.box.widthZ = scale.z;
		object.box.height = scale.y;
		object.box.position = position;
	}

	inline void Render(const StaticObject& object, const Camera& camera)
	{
		spl::Render(object.simpleObject, camera);
	}
}

#endif //STATIC_OBJECT_H
