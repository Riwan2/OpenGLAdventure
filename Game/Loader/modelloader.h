#ifndef MODELLOADER_H
#define MODELLOADER_H

#include <GL/glew.h>
#include <string>
#include <glm/glm.hpp>
#include "objloader.h"

namespace vaoLoader
{
	struct VaoObject {
		objl::Vertex* vertices;
		GLuint* indices;
		GLuint vaoId, modelId;
		glm::vec3 min, max;
		int drawCall, numVertices, numIndices;
		bool instanced;
		VaoObject() {}
		VaoObject(GLuint vId, int nbCall, GLuint mId = 0, bool inst = false) : vaoId(vId), drawCall(nbCall), modelId(mId), instanced(inst)
		{
		}

		void ClearVerticesIndices() {
			delete vertices;
			delete indices;
		}
	};

	inline VaoObject LoadBasicObj(const std::string& fileName);
	inline VaoObject LoadInstancedObj(const std::string& fileName);
	inline VaoObject LoadSkyBox(const float& size = 500); 
	//LOAD INSTANCED OBJ FILE
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
	//LOAD OBJ FILE
	inline VaoObject LoadBasicObj(const std::string& fileName) {
	    objl::Vertex* vertices;
	    GLuint* indices;
	    GLuint VAO, VBO, EBO;
	    int verticesSize, indicesSize, drawCall;
	    glm::vec3 min = glm::vec3(0, 0, 0);
	    glm::vec3 max = glm::vec3(0, 0, 0);
	    
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
	            if (vertices[i].Position.X < min.x) min.x = vertices[i].Position.X;
	            else if (vertices[i].Position.X > max.x) max.x = vertices[i].Position.X;
	            if (vertices[i].Position.Y < min.y) min.y = vertices[i].Position.Y;
	            else if (vertices[i].Position.Y > max.y) max.y = vertices[i].Position.Y;
	            if (vertices[i].Position.Z < min.z) min.z = vertices[i].Position.Z;
	            else if (vertices[i].Position.Z > max.z) max.z = vertices[i].Position.Z;
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
	        glBufferData(GL_ARRAY_BUFFER, (verticesSize + 1) * sizeof(objl::Vertex), vertices, GL_STATIC_DRAW);
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
	    
	    //delete vertices;
	    //delete indices;
	    glDeleteBuffers(1, &VBO);
	    glDeleteBuffers(1, &EBO);

	    VaoObject vaoObject = VaoObject(VAO, drawCall, false);
	    vaoObject.vertices = vertices;
	    vaoObject.indices = indices;
	    vaoObject.numVertices = verticesSize;
	    vaoObject.numIndices = indicesSize;
	    vaoObject.min = min;
	    vaoObject.max = max;
	    return vaoObject;
	}
	//LOAD BASIC TRIANGLE
	inline VaoObject LoadBasicTriangle(const glm::vec3& a, const glm::vec3& b, const glm::vec3& c)
	{
	    const int verticesSize = 24;
	    const int indicesSize = 3;
	    int drawCall = 3;

		objl::Vertex* vertices = new objl::Vertex[verticesSize] {
			objl::Vertex(a.x, a.y, a.z, 0.0, 0.0, 0.0, 0.0, 0.0), //-1.0, 0.0, 0.0
			objl::Vertex(b.x, b.y, b.z, 0.0, 0.0, 0.0, 0.5, 1.0), //0.0, 0.0, 1.0
			objl::Vertex(c.x, c.y, c.z, 0.0, 0.0, 0.0, 1.0, 0.0), //1.0, 0.0, 0.0
		};
		GLuint* indices = new GLuint[indicesSize] {
			0, 1, 2,
		};

		GLuint VAO, VBO, EBO;

		glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);
        glGenBuffers(1, &EBO);
        
        glBindVertexArray(VAO);
            
        glBindBuffer(GL_ARRAY_BUFFER, VBO); //Vertices
        glBufferData(GL_ARRAY_BUFFER, (verticesSize + 1) * sizeof(float), vertices, GL_STATIC_DRAW);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO); //Triangle Indices
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicesSize * sizeof(unsigned int), indices, GL_STATIC_DRAW);
     
        glEnableVertexAttribArray(0); //Position
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);   
        glEnableVertexAttribArray(1); //Normals
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
        glEnableVertexAttribArray(2); //Texture Position
        glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
            
        glBindVertexArray(0);

        glDeleteBuffers(1, &VBO);
	    glDeleteBuffers(1, &EBO);

	    VaoObject vaoObject = VaoObject(VAO, drawCall, false);
	    vaoObject.vertices = vertices;
	    vaoObject.indices = indices;
	    vaoObject.numIndices = indicesSize;
	    vaoObject.numVertices = verticesSize;
	    return vaoObject;
	}
	//LOAD SKY BOX (SIMPLE CUBE) MESH
	inline VaoObject LoadSkyBox(const float& size) 
	{
        int verticesSize = 108;
        int drawCall = verticesSize;

		float* vertices = new float[verticesSize] {
		    -size,  size, -size,
		    -size, -size, -size,
		     size, -size, -size,
		     size, -size, -size,
		     size,  size, -size,
		    -size,  size, -size,

		    -size, -size,  size,
		    -size, -size, -size,
		    -size,  size, -size,
		    -size,  size, -size,
		    -size,  size,  size,
		    -size, -size,  size,

		     size, -size, -size,
		     size, -size,  size,
		     size,  size,  size,
		     size,  size,  size,
		     size,  size, -size,
		     size, -size, -size,

		    -size, -size,  size,
		    -size,  size,  size,
		     size,  size,  size,
		     size,  size,  size,
		     size, -size,  size,
		    -size, -size,  size,

		    -size,  size, -size,
		     size,  size, -size,
		     size,  size,  size,
		     size,  size,  size,
		    -size,  size,  size,
		    -size,  size, -size,

		    -size, -size, -size,
		    -size, -size,  size,
		     size, -size, -size,
		     size, -size, -size,
		    -size, -size,  size,
		     size, -size,  size
		};

	    GLuint VAO, VBO;
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);
        
        glBindVertexArray(VAO);
            
        glBindBuffer(GL_ARRAY_BUFFER, VBO); //Vertices
        glBufferData(GL_ARRAY_BUFFER, verticesSize * 3 * sizeof(float), vertices, GL_STATIC_DRAW);
	     
        glEnableVertexAttribArray(0); //Position
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	            
        glBindVertexArray(0);
	    
	    delete[] vertices;
	    glDeleteBuffers(1, &VBO);

	    return VaoObject(VAO, drawCall, false);
	}
}

#endif // MODELLOADER_H
