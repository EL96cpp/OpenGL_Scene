#include "RectCuboid.h"

RectCuboid::RectCuboid(const float& length, const float& width, const float& height) {


    float length_div2 = length / 2;
    float width_div2 = width / 2;
    float height_div2 = height / 2;
    float thickness = width / height;


    Vertex vertices[] = {

        
        glm::vec3(-length_div2, -height_div2, width_div2),  glm::vec2(1.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f),  glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.0f, 1.0f),   
        glm::vec3( length_div2, -height_div2,  width_div2), glm::vec2(0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f),  glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.0f, 1.0f), 
        glm::vec3(-length_div2,  height_div2,  width_div2), glm::vec2(1.0f, 1.0f), glm::vec3(0.0f, 0.0f, 1.0f),  glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.0f, 1.0f), 
        glm::vec3( length_div2,  height_div2,  width_div2), glm::vec2(0.0f, 1.0f), glm::vec3(0.0f, 0.0f, 1.0f),  glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.0f, 1.0f), 

        // Vertex data for face 1
        glm::vec3( length_div2, -height_div2,  width_div2), glm::vec2(thickness, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.0f, 1.0f),   
        glm::vec3( length_div2, -height_div2, -width_div2), glm::vec2(0.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f),      glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.0f, 1.0f), 
        glm::vec3( length_div2,  height_div2,  width_div2), glm::vec2(thickness, 1.0f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.0f, 1.0f),   
        glm::vec3( length_div2,  height_div2, -width_div2), glm::vec2(0.0f, 1.0f), glm::vec3(1.0f, 0.0f, 0.0f),      glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.0f, 1.0f), 

        // Vertex data for face 2
        glm::vec3( length_div2, -height_div2, -width_div2), glm::vec2(1.0f, 0.0f), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.0f, 1.0f),  
        glm::vec3(-length_div2, -height_div2, -width_div2), glm::vec2(0.0f, 0.0f), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.0f, 1.0f), 
        glm::vec3( length_div2,  height_div2, -width_div2), glm::vec2(1.0f, 1.0f), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.0f, 1.0f), 
        glm::vec3(-length_div2, height_div2, -width_div2),  glm::vec2(0.0f, 1.0f), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.0f, 1.0f), 

        // Vertex data for face 3
        glm::vec3(-length_div2, -height_div2, -width_div2), glm::vec2(thickness, 0.0f), glm::vec3(-1.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.0f, 1.0f),  
        glm::vec3(-length_div2, -height_div2,  width_div2), glm::vec2(0.0f, 0.0f), glm::vec3(-1.0f, 0.0f, 0.0f),      glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.0f, 1.0f), 
        glm::vec3(-length_div2, height_div2, -width_div2),  glm::vec2(thickness, 1.0f), glm::vec3(-1.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.0f, 1.0f), 
        glm::vec3(-length_div2, height_div2, width_div2),   glm::vec2(0.0f, 1.0f), glm::vec3(-1.0f, 0.0f, 0.0f),      glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.0f, 1.0f), 

        // Vertex data for face 4
        glm::vec3(-length_div2, -height_div2, -width_div2), glm::vec2(1.0f, 0.0f), glm::vec3(0.0f, -1.0f, 0.0f),      glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.0f, 1.0f),  
        glm::vec3( length_div2, -height_div2, -width_div2), glm::vec2(0.0f, 0.0f), glm::vec3(0.0f, -1.0f, 0.0f),      glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.0f, 1.0f), 
        glm::vec3(-length_div2, -height_div2,  width_div2), glm::vec2(1.0f, thickness), glm::vec3(0.0f, -1.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.0f, 1.0f), 
        glm::vec3( length_div2, -height_div2, width_div2),  glm::vec2(0.0f, thickness), glm::vec3(0.0f, -1.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.0f, 1.0f), 

        // Vertex data for face 5
        glm::vec3(-length_div2, height_div2, width_div2),   glm::vec2(1.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f),     glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.0f, 1.0f),   
        glm::vec3( length_div2, height_div2, width_div2),   glm::vec2(0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f),     glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.0f, 1.0f), 
        glm::vec3(-length_div2, height_div2, -width_div2),  glm::vec2(1.0f, thickness), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.0f, 1.0f),   
        glm::vec3(length_div2, height_div2, -width_div2),   glm::vec2(0.0f, thickness), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.0f, 1.0f)   
    
    };

    unsigned nrOfVertices = sizeof(vertices) / sizeof(Vertex);

    GLuint indices[] = {
    
        0,  1,  2,  2,  1,  3,    // Face 0 - triangle strip ( v0,  v1,  v2,  v3)
        4,  5,  6,  6,  5,  7, // Face 1 - triangle strip ( v4,  v5,  v6,  v7)
        8,  9,  10, 10, 9, 11, // Face 2 - triangle strip ( v8,  v9, v10, v11)
        12, 13, 14, 14, 13, 15, // Face 3 - triangle strip (v12, v13, v14, v15)
        16, 17, 18, 18, 17, 19, // Face 4 - triangle strip (v16, v17, v18, v19)
        20, 21, 22, 22, 21, 23      // Face 5 - triangle strip (v20, v21, v22, v23)
    
    };
    
    
    unsigned nrOfIndices = sizeof(indices) / sizeof(GLuint);
    
    set(vertices, nrOfVertices, indices, nrOfIndices);

}

