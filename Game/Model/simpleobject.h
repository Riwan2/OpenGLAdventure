#ifndef SIMPLEOBJECT_H
#define SIMPLEOBJECT_H

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "../Basic/camera.h"

namespace spl
{
	struct SimpleObject {
		GLuint vaoId, shaderId;
		glm::mat4 model;
		int drawCall;
		SimpleObject(GLuint vId, int dCall, GLuint sId, glm::mat4 m) : vaoId(vId), shaderId(sId), model(m), drawCall(dCall)
		{
		}
		SimpleObject(const SimpleObject& o) : vaoId(o.vaoId), shaderId(o.shaderId), model(o.model), drawCall(o.drawCall)
		{
		}
	};

	inline void SetPosition(SimpleObject& object, const glm::vec3& position)
	{
		object.model = glm::mat4(1.0);
		object.model = glm::translate(object.model, position);
 		object.model = glm::scale(object.model, glm::vec3(1.0));
    	object.model = glm::rotate(object.model, (float)glm::radians(0.0), glm::vec3(1, 0, 0));
    	object.model = glm::rotate(object.model, (float)glm::radians(0.0), glm::vec3(0, 1, 0));
    	object.model = glm::rotate(object.model, (float)glm::radians(0.0), glm::vec3(0, 0, 1));
	}

	inline void Render(const SimpleObject& object, const Camera& camera)
	{
		glUseProgram(object.shaderId);
		glUniformMatrix4fv(glGetUniformLocation(object.shaderId, "model"), 1, GL_FALSE, glm::value_ptr(object.model));
		glUniformMatrix4fv(glGetUniformLocation(object.shaderId, "view"), 1, GL_FALSE, glm::value_ptr(camera.GetView()));
		glUniformMatrix4fv(glGetUniformLocation(object.shaderId, "projection"), 1, GL_FALSE, glm::value_ptr(camera.GetProjection()));
		glBindVertexArray(object.vaoId);
		glDrawElements(GL_TRIANGLES, object.drawCall, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
	}
}

#endif //SIMPLEOBJECT_H