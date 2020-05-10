#ifndef SIMPLEOBJECT_H
#define SIMPLEOBJECT_H

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "../Basic/camera.h"
#include "../Loader/modelloader.h"
#include "../Loader/texture.h"

namespace spl
{
	struct SimpleObject {
		GLuint vaoId, shaderId, texId;
		glm::mat4 model;
		glm::vec3 position, scale;
		int drawCall;
		SimpleObject(const vaoLoader::VaoObject& obj, const txtl::Texture2d& tex, GLuint sId) : vaoId(obj.vaoId), texId(tex.textureId), drawCall(obj.drawCall), shaderId(sId), model(glm::mat4(1.0))
		{
			position = glm::vec3(0.0);
			scale = glm::vec3(1.0);
		}
		SimpleObject(GLuint vId, int dCall, GLuint sId, glm::mat4 m) : vaoId(vId), shaderId(sId), model(m), drawCall(dCall), texId(0)
		{
			position = glm::vec3(0.0);
			scale = glm::vec3(1.0);
		}
		SimpleObject(const SimpleObject& o) : vaoId(o.vaoId), shaderId(o.shaderId), model(o.model), drawCall(o.drawCall), texId(0)
		{
			position = glm::vec3(0.0);
			scale = glm::vec3(1.0);
		}
	};

	inline void SetModel(SimpleObject& object, const glm::vec3& position, const glm::vec3& scale = glm::vec3(1.0), const float& rotX = 0.0, const float& rotY = 0.0, const float& rotZ = 0.0)
	{
		object.position = position;
		object.scale = scale;
		object.model = glm::mat4(1.0);
		object.model = glm::translate(object.model, position);
		object.model = glm::rotate(object.model, (float)glm::radians(rotX), glm::vec3(1, 0, 0));
    	object.model = glm::rotate(object.model, (float)glm::radians(rotY), glm::vec3(0, 1, 0));
    	object.model = glm::rotate(object.model, (float)glm::radians(rotZ), glm::vec3(0, 0, 1));
 		object.model = glm::scale(object.model, scale);
	}

	inline void Render(const SimpleObject& object, const Camera& camera)
	{
		glUseProgram(object.shaderId);
		glEnable(GL_TEXTURE_2D);
    	glBindTexture(GL_TEXTURE_2D, object.texId);
		glUniformMatrix4fv(glGetUniformLocation(object.shaderId, "model"), 1, GL_FALSE, glm::value_ptr(object.model));
		glUniformMatrix4fv(glGetUniformLocation(object.shaderId, "view"), 1, GL_FALSE, glm::value_ptr(camera.GetView()));
		glUniformMatrix4fv(glGetUniformLocation(object.shaderId, "projection"), 1, GL_FALSE, glm::value_ptr(camera.GetProjection()));
		glBindVertexArray(object.vaoId);
		glDrawElements(GL_TRIANGLES, object.drawCall, GL_UNSIGNED_INT, 0);
    	glDisable(GL_TEXTURE_2D);
		glBindVertexArray(0);
	}
}

#endif //SIMPLEOBJECT_H