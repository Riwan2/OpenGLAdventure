#ifndef MODELLOADER_H
#define MODELLOADER_H

#include <GL/glew.h>
#include <string>
#include <glm/glm.hpp>
#include "objloader.h"

namespace vaoLoader
{
	struct VaoObject {
		GLuint vaoId, modelId;
		int drawCall;
		bool instanced;
		VaoObject() {}
		VaoObject(GLuint vId, int nbCall, GLuint mId = 0, bool inst = false) : vaoId(vId), drawCall(nbCall), modelId(mId), instanced(inst)
		{
		}
	};

	VaoObject LoadBasicObj(const std::string& fileName);
	VaoObject LoadInstancedObj(const std::string& fileName);

	inline VaoObject LoadInstancedObj(const std::string& fileName) 
	{
		VaoObject myVao = LoadBasicObj(fileName);
		GLuint ModelBufferId;
		glBindVertexArray(myVao.vaoId);

		glGenBuffers(1, &ModelBufferId);
        std::size_t vec4Size = sizeof(glm::vec4);
        glBindBuffer(GL_ARRAY_BUFFER, ModelBufferId);
        glBufferData(GL_ARRAY_BUFFER, sizeof(glm::mat4), NULL, GL_STREAM_DRAW);

        glEnableVertexAttribArray(3);
        glVertexAttribPointer(3, 4, GL_FLOAT, GL_FALSE, 4 * vec4Size, (void*)0);
        glEnableVertexAttribArray(4);
        glVertexAttribPointer(4, 4, GL_FLOAT, GL_FALSE, 4 * vec4Size, (void*)(1 * vec4Size));
        glEnableVertexAttribArray(5);
        glVertexAttribPointer(5, 4, GL_FLOAT, GL_FALSE, 4 * vec4Size, (void*)(2 * vec4Size));
        glEnableVertexAttribArray(6);
        glVertexAttribPointer(6, 4, GL_FLOAT, GL_FALSE, 4 * vec4Size, (void*)(3 * vec4Size));

        glVertexAttribDivisor(0, 0);
        glVertexAttribDivisor(3, 1);
        glVertexAttribDivisor(4, 1);
        glVertexAttribDivisor(5, 1);
        glVertexAttribDivisor(6, 1);

        glBindVertexArray(0);
        myVao.modelId = ModelBufferId;
        myVao.instanced = true;
        return myVao;
	}

	inline VaoObject LoadBasicObj(const std::string& fileName) {
	    objl::Vertex* vertices;
	    GLuint* indices;
	    GLuint VAO, VBO, EBO;
	    int verticesSize, indicesSize, drawCall;
	    
		objl::Loader Loader;
	    std::string myFileName = "../Asset/Model/" + fileName + ".obj";
	    bool loaded = Loader.LoadFile(myFileName);
	    
	    if (loaded) {
	        verticesSize = Loader.LoadedMeshes[0].Vertices.size();
	        indicesSize = Loader.LoadedMeshes[0].Indices.size();
	        drawCall = indicesSize;
	        vertices = new objl::Vertex[verticesSize];
	        indices = new unsigned int[indicesSize];
	        
	        for (int i = 0; i < verticesSize; i++) {
	            vertices[i] = Loader.LoadedMeshes[0].Vertices[i];
	            vertices[i].TextureCoordinate.Y = 1 - vertices[i].TextureCoordinate.Y;
	        }
	        for (int i = 0; i < indicesSize; i += 3) {
	        	indices[i] = Loader.LoadedMeshes[0].Indices[i];
	        	indices[i+1] = Loader.LoadedMeshes[0].Indices[i+1];
	        	indices[i+2] = Loader.LoadedMeshes[0].Indices[i+2];
	        }
	    
	        glGenVertexArrays(1, &VAO);
	        glGenBuffers(1, &VBO);
	        glGenBuffers(1, &EBO);
	        
	        glBindVertexArray(VAO);
	            
	        glBindBuffer(GL_ARRAY_BUFFER, VBO); //Vertices
	        glBufferData(GL_ARRAY_BUFFER, verticesSize * sizeof(objl::Vertex), vertices, GL_STATIC_DRAW);
	        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO); //Triangle Indices
	        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicesSize * sizeof(unsigned int), indices, GL_STATIC_DRAW);
	     
	        glEnableVertexAttribArray(0); //Position
	        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);   
	        glEnableVertexAttribArray(1); //Normals
	        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	        glEnableVertexAttribArray(2); //Texture Position
	        glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	            
	        glBindVertexArray(0);
	    } else {
	        std::cerr << "Failed to load model : " << fileName << std::endl;
	    }
	    
	    delete vertices;
	    delete indices;
	    glDeleteBuffers(1, &VBO);
	    glDeleteBuffers(1, &EBO);

	    return VaoObject(VAO, drawCall, false);
	}
}

#endif // MODELLOADER_H
