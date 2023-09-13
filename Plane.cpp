#include "Plane.h"

Plane::Plane(const float& length, const float& width) {

    float length_div2 = length / 2;
    float width_div2 = width / 2;

    Vertex vertices[] = {

        
        glm::vec3(-width_div2, 0.0f, width_div2),  glm::vec2(1.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f),  glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.0f, 1.0f),  
        glm::vec3( width_div2, 0.0f, width_div2),  glm::vec2(0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f),  glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.0f, 1.0f), 
        glm::vec3(-width_div2, 0.0f, -width_div2), glm::vec2(1.0f, 1.0f), glm::vec3(0.0f, 1.0f, 0.0f),  glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.0f, 1.0f), 
        glm::vec3( width_div2, 0.0f, -width_div2), glm::vec2(0.0f, 1.0f), glm::vec3(0.0f, 1.0f, 0.0f),  glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.0f, 1.0f) 

   
    };

    unsigned nrOfVertices = sizeof(vertices) / sizeof(Vertex);
    

    GLuint indices[] = {
    
        0,  1,  2,  2,  1,  3,    // Face 0 - triangle strip ( v0,  v1,  v2,  v3)
   
    };
    
    
    unsigned nrOfIndices = sizeof(indices) / sizeof(GLuint);
    
    set(vertices, nrOfVertices, indices, nrOfIndices);

}

