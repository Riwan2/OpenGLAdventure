#include "../headers/objloader.h"
#include <fstream>

OBJLoader::OBJLoader(const std::string& fileName) {
    std::ifstream file;
    std::string myFileName = "../Asset/Model/" + fileName + ".obj";
    file.open(myFileName.c_str());
    
    std::vector<glm::vec3> FileVertices;
    std::vector<glm::vec3> FileNormals;
    std::vector<glm::vec2> FileTexCoords;
    std::vector<unsigned int> FileIndices;
    
    float* textureArray;
    float* normalsArray;
    
    std::string line;
    if (!file.is_open()) {
        std::cout << "Error : file : "  << fileName << " is not found" << std::endl;
    } else {
        while (true) {
            getline(file, line);
            
            if (line[0] == 'v' && line[1] == ' ') {
                FileVertices.push_back(ParseFloat3(line, 2));
            } else if (line[0] == 'v' && line[1] == 't') {
                FileTexCoords.push_back(ParseFloat2(line));
            } else if (line[0] == 'v' && line[1] == 'n') {
                FileNormals.push_back(ParseFloat3(line, 3));
            } else if (line[0] == 'f') {
                normalsArray = new float[FileVertices.size() * 3];
                textureArray = new float[FileVertices.size() * 2];
                ProcessLine(line, FileVertices, FileNormals, FileTexCoords, &textureArray[0], &normalsArray[0], FileIndices);
                break;
            }
        }
        
        while (file.good()) {
            getline(file, line);
            if (line.size() < 2) break;
            ProcessLine(line, FileVertices, FileNormals, FileTexCoords, &textureArray[0], &normalsArray[0], FileIndices);
        }
    }
    file.close();
    
    m_verticesSize = FileVertices.size() * 8 * sizeof(float);
    m_indicesSize = FileIndices.size() * sizeof(unsigned int);
    m_drawCall = FileIndices.size();
    vertices = new float[FileVertices.size() * 8];
    indices = new unsigned int[FileIndices.size()];
    
    int vertexIndice = 0;
    for (int i = 0; i < FileVertices.size(); i++) {
        vertices[i*8] = FileVertices[i].x;
        vertices[i*8 + 1] = FileVertices[i].y;
        vertices[i*8 + 2] = FileVertices[i].z;
        vertices[i*8 + 3] = normalsArray[i*3];
        vertices[i*8 + 4] = normalsArray[i*3+1];
        vertices[i*8 + 5] = normalsArray[i*3+2];
        vertices[i*8 + 6] = textureArray[i*2];
        vertices[i*8 + 7] = textureArray[i*2+1];
    }
    
    for (int i = 0; i < FileIndices.size(); i++) {
        indices[i] = FileIndices[i];
    }
    
    //PrintData(FileVertices, FileNormals, FileTexCoords);
}

OBJLoader::~OBJLoader()
{
    
}

void OBJLoader::ProcessLine(const std::string& line, const std::vector<glm::vec3>& FileVertices, const std::vector<glm::vec3>& FileNormals, const std::vector<glm::vec2>& FileTexCoords, float* textureArray,float* normalsArray, std::vector<unsigned int>& FileIndices) 
{
    unsigned int data[9];
    ParseIndexData(line, &data[0]);
    
    glm::vec3 vertex1 = glm::vec3(data[0], data[1], data[2]);
    glm::vec3 vertex2 = glm::vec3(data[3], data[4], data[5]);
    glm::vec3 vertex3 = glm::vec3(data[6], data[7], data[8]);
    
    ProcessVertex(vertex1, FileVertices, FileNormals, FileTexCoords, &textureArray[0], &normalsArray[0], FileIndices);
    ProcessVertex(vertex2, FileVertices, FileNormals, FileTexCoords, &textureArray[0], &normalsArray[0], FileIndices);
    ProcessVertex(vertex3, FileVertices, FileNormals, FileTexCoords, &textureArray[0], &normalsArray[0], FileIndices);
}

void OBJLoader::ProcessVertex(const glm::vec3& vertexData, const std::vector<glm::vec3>& FileVertices, const std::vector<glm::vec3>& FileNormals, const std::vector<glm::vec2>& FileTexCoords, float* textureArray,float* normalsArray, std::vector<unsigned int>& FileIndices) 
{
    int VertexPointer = vertexData.x - 1;
    FileIndices.push_back(VertexPointer);
    
    glm::vec2 texCoord = FileTexCoords[vertexData.y - 1];
    textureArray[VertexPointer*2] = texCoord.x;
    textureArray[VertexPointer*2+1] = 1 - texCoord.y;
    
    glm::vec3 normal = FileNormals[vertexData.z - 1];
    normalsArray[VertexPointer*3] = normal.x;
    normalsArray[VertexPointer*3+1] = normal.y;
    normalsArray[VertexPointer*3+2] = normal.z;
}

void OBJLoader::ParseIndexData(const std::string& line, unsigned int* container)
{
    int index = 0;
    int end = 0;
    int begining = 2;
    for (int i = 2; i < line.size(); i++) {
        if (line[i] != '/' && line[i] != ' ')
            end++;
        if (line[i] == '/' || line[i] == ' ' || i == line.size() - 1) {
            container[index] = atoi(line.substr(begining, end).c_str());
            begining += end + 1;
            end = 0;
            index++;
        }
    }
}

glm::vec3 OBJLoader::ParseFloat3(const std::string& line, const int& firstIndex)
{
    float data[3];
    ParseFloatData(line, firstIndex, 3, &data[0]);
    return glm::vec3(data[0], data[1], data[2]);
}

glm::vec2 OBJLoader::ParseFloat2(const std::string& line) {
    float data[2];
    ParseFloatData(line, 3, 2, &data[0]);
    return glm::vec2(data[0], data[1]);
}

void OBJLoader::ParseFloatData(const std::string& line, const int& firstIndex, int dataSize, float* container)
{
    int index = 0;
    int end = 0;
    int begining = firstIndex;
    for (int i = firstIndex; i < line.size(); i++) {
        if (line[i] != ' ')
            end++;
        if (line[i] == ' ' || i == line.size() - 1) {
            end++;
            container[index] = atof(line.substr(begining, end).c_str());
            index++;
            begining += end;
            end = 0;
        }
    }
}

void OBJLoader::PrintData(const std::vector<glm::vec3>& FileVertices, const std::vector<glm::vec3>& FileNormals,
    const std::vector<glm::vec2>& FileTexCoords)
{
    std::cout << "Vertices : " << std::endl;
    for (int i = 0; i < FileVertices.size(); i++) {
       std::cout << FileVertices[i].x << " ; " << FileVertices[i].y << " ; " << FileVertices[i].z << std::endl;
    }
    std::cout << std::endl << "Normals : " << std::endl;
    for (int i = 0; i < FileNormals.size(); i++) {
        std::cout << FileNormals[i].x << " ; " << FileNormals[i].y << " ; " << FileNormals[i].z << std::endl;
    }
    std::cout << std::endl << "Texture coordinate" << std::endl;
    for (int i = 0; i < FileTexCoords.size(); i++) {
        std::cout << FileTexCoords[i].x << " ; " << FileTexCoords[i].y << std::endl;
    }
}

