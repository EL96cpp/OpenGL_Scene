#pragma once

#include <iostream>
#include <vector>

#include "Vertex.h"
#include "Shader.h"
#include "Texture.h"
#include "Primitive.h"


class Mesh {

    public:
        Mesh(Vertex* vertexArray, const unsigned& nrOfVertices, GLuint* indexArray, const unsigned& nrOfIndices,
             glm::vec3 position = glm::vec3(0.0f), glm::vec3 rotation = glm::vec3(0.0f), glm::vec3 scale = glm::vec3(1.0f));

        Mesh(Primitive* primitive, glm::vec3 position = glm::vec3(0.0f), 
             glm::vec3 rotation = glm::vec3(0.0f), glm::vec3 scale = glm::vec3(1.0f));


        ~Mesh();
        
        void setPosition(const glm::vec3 position);
        void setRotation(const glm::vec3 rotation);
        void setScale(const glm::vec3 scale);
        void Move(const glm::vec3 position);
        void Rotate(const glm::vec3 rotation);
        void Scale(const glm::vec3 scale);

        void update();
        void render(Shader* shader);
    
    private:
        void initVAO(Vertex* vertexArray, const unsigned& nrOfVertices,
                     GLuint* indexArray, const unsigned& nrOfIndices);
        
        void initVAO(Primitive* primitive);
        void initModelMatrix();
        void updateModelMatrix();
        void updateUniforms(Shader* shader);

    private:
        unsigned nrOfVertices;
        unsigned nrOfIndices;

        std::vector<Vertex> vertices;
        std::vector<GLuint> indices;
        
        GLuint VAO;
        GLuint VBO;
        GLuint EBO;
    
        glm::vec3 position;
        glm::vec3 rotation;
        glm::vec3 scale;
        glm::mat4 ModelMatrix;
};
