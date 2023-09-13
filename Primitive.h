#pragma once 

#include <vector>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Vertex.h"


class Primitive {

    public:
        //Primitive();
        //virtual ~Primitive();

        void set(const Vertex* vertices, const unsigned nrOfVertices,
                 const GLuint* indices, const unsigned nrOfIndices);
        Vertex* getVertices();
        GLuint* getIndices();
        const unsigned getNrOfVertices();
        const unsigned getNrOfIndices();
        
        void addTangentsAndBitangents();

    protected:
        std::vector<Vertex> vertices;
        std::vector<GLuint> indices; 

};
