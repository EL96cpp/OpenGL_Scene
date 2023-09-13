#include <iostream>
#include <fstream>
#include <GL/glew.h>
#include <SOIL/SOIL.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Vertex.h"
#include "Primitive.h"
#include "Shader.h"
#include "Texture.h"
#include "Material.h"
#include "Mesh.h"
#include "Quad.h"
#include "Game.h"






int main() {
    
    Game game("OpenGL", 1920, 1080, 3, 3, true);

    while (!game.getWindowShouldClose()) {
        
        game.update();
        game.render();

    }
    
    return 0;
}
