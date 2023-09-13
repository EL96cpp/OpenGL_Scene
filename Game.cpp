#include "Game.h"


void Game::updateKeyboardInput() {


    if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) {
        
        camera.changeBendDown();

    }

    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        
        setWindowShouldClose();

    }

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {

        camera.updateKeyboardInput(dt, FORWARD);

    }

    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
        
        camera.updateKeyboardInput(dt, BACKWARD);
    
    }

    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
   
        camera.updateKeyboardInput(dt, LEFT);
    
    }

    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {

        camera.updateKeyboardInput(dt, RIGHT);

    }

}


void Game::updateMouseInput() {

    glfwGetCursorPos(window, &mouseX, &mouseY);

    if (firstMouse) {

        lastMouseX = mouseX;
        lastMouseY = mouseY;
        firstMouse = false;

    }

    mouseOffsetX = mouseX - lastMouseX;
    mouseOffsetY = lastMouseY - mouseY;
    
    lastMouseX = mouseX;
    lastMouseY = mouseY;

}

void Game::updateInput() {

    glfwPollEvents();

    updateKeyboardInput();
    updateMouseInput();
    camera.updateInput(dt, -1, mouseOffsetX, mouseOffsetY);

}

void Game::initWindow(const char* title, const bool& resizable) {

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, GL_VERSION_MAJOR);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, GL_VERSION_MINOR);
    glfwWindowHint(GLFW_RESIZABLE, resizable);

    //create window

    window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, title, NULL, NULL);

    glfwGetFramebufferSize(window, &framebufferWidth, &framebufferHeight);
    
    glfwSetFramebufferSizeCallback(window, framebuffer_resize_callback);

    glfwMakeContextCurrent(window);
        
}


void Game::initTextures() {

    std::vector<Texture*> brick_tile_vec;
    brick_tile_vec.push_back(new Texture("Textures/brick_tile.png", GL_TEXTURE_2D));
    brick_tile_vec.push_back(new Texture("SpecularMaps/brick_specular.png", GL_TEXTURE_2D));
    brick_tile_vec.push_back(new Texture("NormalMaps/brick_normal.png", GL_TEXTURE_2D));
    brick_tile_vec.push_back(new Texture("HeightMaps/brick_height.png", GL_TEXTURE_2D));
    textures.emplace("Brick_tile", brick_tile_vec);


    std::vector<Texture*> brick_wall_vec;
    brick_wall_vec.push_back(new Texture("Textures/brick_wall.png", GL_TEXTURE_2D));
    brick_wall_vec.push_back(new Texture("SpecularMaps/brick_wall_specular.png", GL_TEXTURE_2D));
    brick_wall_vec.push_back(new Texture("NormalMaps/brick_wall_normal.png", GL_TEXTURE_2D));
    brick_wall_vec.push_back(new Texture("HeightMaps/brick_wall_height.png", GL_TEXTURE_2D));
    textures.emplace("Brick_wall", brick_wall_vec);



    std::vector<Texture*> concrete_wall_vec;
    concrete_wall_vec.push_back(new Texture("Textures/concrete_wall.png", GL_TEXTURE_2D));
    concrete_wall_vec.push_back(new Texture("SpecularMaps/concrete_wall_specular.png", GL_TEXTURE_2D));
    concrete_wall_vec.push_back(new Texture("NormalMaps/concrete_wall_normal.png", GL_TEXTURE_2D));
    concrete_wall_vec.push_back(new Texture("HeightMaps/concrete_wall_height.png", GL_TEXTURE_2D));
    textures.emplace("Concrete_wall", concrete_wall_vec);

    std::vector<Texture*> floor_tile_vec;
    floor_tile_vec.push_back(new Texture("Textures/floor_tile.png", GL_TEXTURE_2D));
    floor_tile_vec.push_back(new Texture("SpecularMaps/floor_tile_specular.png", GL_TEXTURE_2D));
    floor_tile_vec.push_back(new Texture("NormalMaps/floor_tile_normal.png", GL_TEXTURE_2D));
    floor_tile_vec.push_back(new Texture("HeightMaps/floor_tile_height.png", GL_TEXTURE_2D));
    textures.emplace("Floor_tile", floor_tile_vec);
 

    std::vector<Texture*> stone_tile_vec;
    stone_tile_vec.push_back(new Texture("Textures/stone_tile.png", GL_TEXTURE_2D));
    stone_tile_vec.push_back(new Texture("SpecularMaps/stone_tile_specular.png", GL_TEXTURE_2D));
    stone_tile_vec.push_back(new Texture("NormalMaps/stone_tile_normal.png", GL_TEXTURE_2D));
    stone_tile_vec.push_back(new Texture("HeightMaps/stone_tile_height.png", GL_TEXTURE_2D));
    textures.emplace("Stone_tile", stone_tile_vec);


    std::vector<Texture*> stone_wall_vec;
    stone_wall_vec.push_back(new Texture("Textures/stone_wall.png", GL_TEXTURE_2D));
    stone_wall_vec.push_back(new Texture("SpecularMaps/stone_wall_specular.png", GL_TEXTURE_2D));
    stone_wall_vec.push_back(new Texture("NormalMaps/stone_wall_normal.png", GL_TEXTURE_2D));
    stone_wall_vec.push_back(new Texture("HeightMaps/stone_wall_height.png", GL_TEXTURE_2D));
    textures.emplace("Stone_wall", stone_wall_vec);

    std::vector<Texture*> wooden_box_vec;
    wooden_box_vec.push_back(new Texture("Textures/wooden_box.png", GL_TEXTURE_2D));
    wooden_box_vec.push_back(new Texture("SpecularMaps/wooden_box_specular.png", GL_TEXTURE_2D));
    wooden_box_vec.push_back(new Texture("NormalMaps/wooden_box_normal.png", GL_TEXTURE_2D));
    wooden_box_vec.push_back(new Texture("HeightMaps/wooden_box_height.png", GL_TEXTURE_2D));
    textures.emplace("Wooden_box", wooden_box_vec);

    std::vector<Texture*> wooden_box_2_vec;
    wooden_box_2_vec.push_back(new Texture("Textures/wooden_box_2.png", GL_TEXTURE_2D));
    wooden_box_2_vec.push_back(new Texture("SpecularMaps/wooden_box_2_specular.png", GL_TEXTURE_2D));
    wooden_box_2_vec.push_back(new Texture("NormalMaps/wooden_box_2_normal.png", GL_TEXTURE_2D));
    wooden_box_2_vec.push_back(new Texture("HeightMaps/wooden_box_2_height.png", GL_TEXTURE_2D));
    textures.emplace("Wooden_box_2", wooden_box_2_vec);;



    std::vector<Texture*> wooden_fence_vec;        
    wooden_fence_vec.push_back(new Texture("Textures/wooden_fence.png", GL_TEXTURE_2D));
    wooden_fence_vec.push_back(new Texture("SpecularMaps/wooden_fence_specular.png", GL_TEXTURE_2D));
    wooden_fence_vec.push_back(new Texture("NormalMaps/wooden_fence_normal.png", GL_TEXTURE_2D));
    wooden_fence_vec.push_back(new Texture("HeightMaps/wooden_fence_height.png", GL_TEXTURE_2D));
    textures.emplace("Wooden_fence", wooden_fence_vec);


}

void Game::initMaterials() {

    materials.emplace("Brick_tile", new Material(glm::vec3(0.05f), glm::vec3(1.5f), glm::vec3(1.f), 0, 1, 2)); 
    materials.emplace("Brick_wall", new Material(glm::vec3(0.1f), glm::vec3(1.5f), glm::vec3(2.0f), 0, 1, 2)); 
    materials.emplace("Concrete_wall", new Material(glm::vec3(0.1f), glm::vec3(1.5f), glm::vec3(0.5f), 0, 1, 2)); 
    materials.emplace("Floor_tile", new Material(glm::vec3(0.1f), glm::vec3(1.5f), glm::vec3(1.5f), 0, 1, 2)); 
    materials.emplace("Stone_tile", new Material(glm::vec3(0.5f), glm::vec3(1.5f), glm::vec3(1.5f), 0, 1, 2)); 
    materials.emplace("Stone_wall", new Material(glm::vec3(0.1f), glm::vec3(1.5f), glm::vec3(1.5f), 0, 1, 2)); 
    materials.emplace("Wooden_box", new Material(glm::vec3(0.1f), glm::vec3(1.5f), glm::vec3(1.5f), 0, 1, 2)); 
    materials.emplace("Wooden_box_2", new Material(glm::vec3(0.1f), glm::vec3(1.5f), glm::vec3(1.5f), 0, 1, 2)); 
    materials.emplace("Wooden_fence", new Material(glm::vec3(0.1f), glm::vec3(1.5f), glm::vec3(1.5f), 0, 1, 2)); 
    materials.emplace("Skybox", new Material(glm::vec3(0.1f), glm::vec3(1.5f), glm::vec3(1.5f), 0, 1, 2)); 


}


void Game::initLights() {


//    lightPos = glm::vec3(0.0f, 0.0f, 2.0f);
    lightPos = camera.getPosition();

}

void Game::initUniforms() {

    core_program->setMat4fv(ViewMatrix, "ViewMatrix");

    core_program->setVec3f(camPosition, "cameraPos");

    core_program->setMat4fv(ProjectionMatrix, "ProjectionMatrix");

    core_program->setVec3f(lightPos, "lightPos0");
   

}

void Game::initMeshes() {


    // Tile meshes
    
    for (int z = -12.0f; z <= 2.0f; z += 1.0f) {

        for (int x = -8.0f; x <= 8.0f; x += 1.0f) {

            floor_tile_meshes.push_back(new Mesh(new Plane(1.0f, 1.0f), glm::vec3(x, -3.0f, z),
                                                     glm::vec3(0.0f), glm::vec3(1.0f)));

        } 

    }

    for (int z = -13.0f; z >= -14.0f; z -= 1.0f) {

        for (int x = -2.0f; x <= 1.0f; x += 1.0f) {

            floor_tile_meshes.push_back(new Mesh(new Plane(1.0f, 1.0f), glm::vec3(x, -3.0f, z),
                                                     glm::vec3(0.0f), glm::vec3(1.0f)));

        } 

    }


    for (int z = -15.0f; z >= -30.0f; z -= 1.0f) {

        for (int x = -8.0f; x <= 8.0f; x += 1.0f) {

            floor_tile_meshes.push_back(new Mesh(new Plane(1.0f, 1.0f), glm::vec3(x, -3.0f, z),
                                                     glm::vec3(0.0f), glm::vec3(1.0f)));

        } 

    }


    // Wall meshes
    brick_wall_meshes.push_back(new Mesh(new RectCuboid(2.0f, 0.2f, 1.0f), glm::vec3(-1.9f, -2.5f, -3.0f), glm::vec3(0.0f, 90.0f, 0.0f), glm::vec3(1.0f)));
    brick_wall_meshes.push_back(new Mesh(new RectCuboid(2.0f, 0.2f, 1.0f), glm::vec3(-1.9f, -1.5f, -3.0f), glm::vec3(0.0f, 90.0f, 0.0f), glm::vec3(1.0f)));
    brick_wall_meshes.push_back(new Mesh(new RectCuboid(2.0f, 0.2f, 1.0f), glm::vec3(-1.9f, -2.5f, -5.0f), glm::vec3(0.0f, 90.0f, 0.0f), glm::vec3(1.0f)));
    brick_wall_meshes.push_back(new Mesh(new RectCuboid(2.0f, 0.2f, 1.0f), glm::vec3(-1.9f, -1.5f, -5.0f), glm::vec3(0.0f, 90.0f, 0.0f), glm::vec3(1.0f)));


    brick_wall_meshes.push_back(new Mesh(new RectCuboid(2.0f, 0.2f, 1.0f), glm::vec3(-1.9f, -2.5f, -7.0f), glm::vec3(0.0f, 90.0f, 0.0f), glm::vec3(1.0f)));
    brick_wall_meshes.push_back(new Mesh(new RectCuboid(2.0f, 0.2f, 1.0f), glm::vec3(-1.9f, -1.5f, -7.0f), glm::vec3(0.0f, 90.0f, 0.0f), glm::vec3(1.0f)));
    brick_wall_meshes.push_back(new Mesh(new RectCuboid(2.0f, 0.2f, 1.0f), glm::vec3(-1.9f, -2.5f, -9.0f), glm::vec3(0.0f, 90.0f, 0.0f), glm::vec3(1.0f)));
    brick_wall_meshes.push_back(new Mesh(new RectCuboid(2.0f, 0.2f, 1.0f), glm::vec3(-1.9f, -1.5f, -9.0f), glm::vec3(0.0f, 90.0f, 0.0f), glm::vec3(1.0f)));

  
    brick_wall_meshes.push_back(new Mesh(new RectCuboid(2.0f, 0.2f, 1.0f), glm::vec3(1.3f, -2.5f, -3.0f), glm::vec3(0.0f, 90.0f, 0.0f), glm::vec3(1.0f)));
    brick_wall_meshes.push_back(new Mesh(new RectCuboid(2.0f, 0.2f, 1.0f), glm::vec3(1.3f, -1.5f, -3.0f), glm::vec3(0.0f, 90.0f, 0.0f), glm::vec3(1.0f)));
    brick_wall_meshes.push_back(new Mesh(new RectCuboid(2.0f, 0.2f, 1.0f), glm::vec3(1.3f, -2.5f, -5.0f), glm::vec3(0.0f, 90.0f, 0.0f), glm::vec3(1.0f)));
    brick_wall_meshes.push_back(new Mesh(new RectCuboid(2.0f, 0.2f, 1.0f), glm::vec3(1.3f, -1.5f, -5.0f), glm::vec3(0.0f, 90.0f, 0.0f), glm::vec3(1.0f)));




    brick_wall_meshes.push_back(new Mesh(new RectCuboid(2.0f, 0.2f, 1.0f), glm::vec3(1.3f, -2.5f, -7.0f), glm::vec3(0.0f, 90.0f, 0.0f), glm::vec3(1.0f)));
    brick_wall_meshes.push_back(new Mesh(new RectCuboid(2.0f, 0.2f, 1.0f), glm::vec3(1.3f, -1.5f, -7.0f), glm::vec3(0.0f, 90.0f, 0.0f), glm::vec3(1.0f)));
    brick_wall_meshes.push_back(new Mesh(new RectCuboid(2.0f, 0.2f, 1.0f), glm::vec3(1.3f, -2.5f, -9.0f), glm::vec3(0.0f, 90.0f, 0.0f), glm::vec3(1.0f)));
    brick_wall_meshes.push_back(new Mesh(new RectCuboid(2.0f, 0.2f, 1.0f), glm::vec3(1.3f, -1.5f, -9.0f), glm::vec3(0.0f, 90.0f, 0.0f), glm::vec3(1.0f)));




    brick_wall_meshes.push_back(new Mesh(new RectCuboid(2.0f, 0.2f, 1.0f), glm::vec3(1.5f, -2.5f, -20.9f), glm::vec3(0.0f), glm::vec3(1.0f)));
    brick_wall_meshes.push_back(new Mesh(new RectCuboid(2.0f, 0.2f, 1.0f), glm::vec3(1.5f, -1.5f, -20.9f), glm::vec3(0.0f), glm::vec3(1.0f)));
    brick_wall_meshes.push_back(new Mesh(new RectCuboid(2.0f, 0.2f, 1.0f), glm::vec3(3.5f, -2.5f, -20.9f), glm::vec3(0.0f), glm::vec3(1.0f)));
    brick_wall_meshes.push_back(new Mesh(new RectCuboid(2.0f, 0.2f, 1.0f), glm::vec3(3.5f, -1.5f, -20.9f), glm::vec3(0.0f), glm::vec3(1.0f)));



    brick_wall_meshes.push_back(new Mesh(new RectCuboid(2.0f, 0.2f, 1.0f), glm::vec3(-0.5f, -2.5f, -20.9f), glm::vec3(0.0f), glm::vec3(1.0f)));
    brick_wall_meshes.push_back(new Mesh(new RectCuboid(2.0f, 0.2f, 1.0f), glm::vec3(-0.5f, -1.5f, -20.9f), glm::vec3(0.0f), glm::vec3(1.0f)));
    brick_wall_meshes.push_back(new Mesh(new RectCuboid(2.0f, 0.2f, 1.0f), glm::vec3(-2.5f, -2.5f, -20.9f), glm::vec3(0.0f), glm::vec3(1.0f)));
    brick_wall_meshes.push_back(new Mesh(new RectCuboid(2.0f, 0.2f, 1.0f), glm::vec3(-2.5f, -1.5f, -20.9f), glm::vec3(0.0f), glm::vec3(1.0f)));




    concrete_wall_meshes.push_back(new Mesh(new RectCuboid(3.0f, 1.0f, 2.0f), glm::vec3(-3.25f, -2.0f, -1.5f), glm::vec3(0.0f), glm::vec3(1.0f)));
    concrete_wall_meshes.push_back(new Mesh(new RectCuboid(2.0f, 1.0f, 2.0f), glm::vec3(2.16f, -2.0f, -1.5f), glm::vec3(0.0f), glm::vec3(1.0f)));
    concrete_wall_meshes.push_back(new Mesh(new RectCuboid(1.0f, 3.0f, 2.0f), glm::vec3(3.66f, -2.0f, -2.5f), glm::vec3(0.0f), glm::vec3(1.0f)));
    concrete_wall_meshes.push_back(new Mesh(new RectCuboid(1.0f, 3.0f, 2.0f), glm::vec3(-4.5f, -2.0f, -8.5f), glm::vec3(0.0f), glm::vec3(1.0f)));
    concrete_wall_meshes.push_back(new Mesh(new RectCuboid(2.0f, 1.0f, 2.0f), glm::vec3(-3.0f, -2.0f, -9.5f), glm::vec3(0.0f), glm::vec3(1.0f)));
    concrete_wall_meshes.push_back(new Mesh(new RectCuboid(3.0f, 1.0f, 2.0f), glm::vec3(2.9f, -2.0f, -9.5f), glm::vec3(0.0f), glm::vec3(1.0f)));

    for (float y = -2.5f; y <= -1.5f; y += 1.0f) {

        for (float z = -21.5f; z >= -26.5f; z -= 1.0f) {
    
            stone_wall_meshes.push_back(new Mesh(new Cube(1.0f), glm::vec3(0.5f, y, z), glm::vec3(0.0f), glm::vec3(1.0f)));
           

        }

    }


    for (float y = -2.5f; y <= -1.5f; y += 1.0f) {

        for (float x = -4.5f; x <= 3.5f; x += 1.0f) {
    
            stone_wall_meshes.push_back(new Mesh(new Cube(1.0f), glm::vec3(x, y, -26.5f), glm::vec3(0.0f), glm::vec3(1.0f)));
           

        }

    }


    // Box meshes
    big_box_meshes.push_back(new Mesh(new Cube(1.0f), glm::vec3(-2.5f, -2.5f, -4.0f), glm::vec3(0.0f), glm::vec3(1.0f)));
    small_box_meshes.push_back(new Mesh(new Cube(0.5f), glm::vec3(-2.4f, -1.75f, -4.1f), glm::vec3(0.0f), glm::vec3(1.0f)));
    big_box_meshes.push_back(new Mesh(new Cube(1.0f), glm::vec3(2.0f, -2.5f, -7.0f), glm::vec3(0.0f), glm::vec3(1.0f)));
    small_box_meshes.push_back(new Mesh(new Cube(0.5f), glm::vec3(2.1f, -1.75f, -6.9f), glm::vec3(0.0f), glm::vec3(1.0f)));

    big_box_meshes.push_back(new Mesh(new Cube(1.0f), glm::vec3(-1.3f, -2.5f, -3.4f), glm::vec3(0.0f), glm::vec3(1.0f)));
    small_box_meshes.push_back(new Mesh(new Cube(0.5f), glm::vec3(-1.4f, -1.75f, -3.3f), glm::vec3(0.0f), glm::vec3(1.0f)));
    small_box_meshes.push_back(new Mesh(new Cube(0.5f), glm::vec3(-1.45f, -2.75f, -4.8f), glm::vec3(0.0f, 20.0f, 0.0f), glm::vec3(1.0f)));  
    small_box_meshes.push_back(new Mesh(new Cube(0.5f), glm::vec3(-1.4f, -2.75f, -4.2f), glm::vec3(0.0f), glm::vec3(1.0f)));  
    small_box_meshes.push_back(new Mesh(new Cube(0.5f), glm::vec3(-1.55f, -2.25f, -4.6f), glm::vec3(0.0f), glm::vec3(1.0f)));  

    //
    small_box_meshes.push_back(new Mesh(new Cube(0.5f), glm::vec3(3.4f, -1.75f, -15.5f), glm::vec3(0.0f, 10.0f, 0.0f), glm::vec3(1.0f)));
    small_box_meshes.push_back(new Mesh(new Cube(0.5f), glm::vec3(3.3f, -2.75f, -17.3f), glm::vec3(0.0f, 5.0f, 0.0f), glm::vec3(1.0f)));  

    small_box_meshes.push_back(new Mesh(new Cube(0.5f), glm::vec3(-2.5f, -1.75f, -21.5f), glm::vec3(0.0f, 10.0f, 0.0f), glm::vec3(1.0f)));  
    small_box_meshes.push_back(new Mesh(new Cube(0.5f), glm::vec3(3.3f, -1.75f, -21.6f), glm::vec3(0.0f, 30.0f, 0.0f), glm::vec3(1.0f)));  
   
    //// 
    small_box_meshes.push_back(new Mesh(new Cube(0.5f), glm::vec3(3.4f, -1.75f, -16.1f), glm::vec3(0.0f, 14.0f, 0.0f), glm::vec3(1.0f)));
    small_box_meshes.push_back(new Mesh(new Cube(0.5f), glm::vec3(3.39f, -2.25f, -17.3f), glm::vec3(0.0f), glm::vec3(1.0f)));  
    

    small_box_meshes.push_back(new Mesh(new Cube(0.5f), glm::vec3(3.4f, -1.75f, -27.6f), glm::vec3(0.0f), glm::vec3(1.0f)));  
    small_box_meshes.push_back(new Mesh(new Cube(0.5f), glm::vec3(2.55f, -2.75f, -27.4f), glm::vec3(0.0f), glm::vec3(1.0f)));  

    
    big_box_meshes.push_back(new Mesh(new Cube(1.0f), glm::vec3(3.3f, -2.5f, -15.5f), glm::vec3(0.0f), glm::vec3(1.0f)));
    big_box_meshes.push_back(new Mesh(new Cube(1.0f), glm::vec3(3.3f, -2.5f, -16.5f), glm::vec3(0.0f), glm::vec3(1.0f)));
    big_box_meshes.push_back(new Mesh(new Cube(1.0f), glm::vec3(-2.5f, -2.5f, -21.5f), glm::vec3(0.0f), glm::vec3(1.0f)));
    big_box_meshes.push_back(new Mesh(new Cube(1.0f), glm::vec3(3.3f, -2.5f, -21.5f), glm::vec3(0.0f), glm::vec3(1.0f)));
    big_box_meshes.push_back(new Mesh(new Cube(1.0f), glm::vec3(3.3f, -2.5f, -22.5f), glm::vec3(0.0f), glm::vec3(1.0f)));
    big_box_meshes.push_back(new Mesh(new Cube(1.0f), glm::vec3(3.3f, -2.5f, -27.5f), glm::vec3(0.0f), glm::vec3(1.0f)));

   

}

void Game::initModels() {


    for (int i = 0; i < floor_tile_meshes.size(); ++i) {

        floor_tile_models.push_back(new Model(materials["Floor_tile"],
                                              textures["Floor_tile"][0],
                                              textures["Floor_tile"][1],
                                              textures["Floor_tile"][2],
                                              textures["Floor_tile"][3],
                                              floor_tile_meshes[i]));
    
    }


    for (int i = 0; i < big_box_meshes.size(); ++i) {

        big_box_models.push_back(new Model(materials["Wooden_box"], textures["Wooden_box"][0], textures["Wooden_box"][1], 
                                           textures["Wooden_box"][2], textures["Wooden_box"][3], big_box_meshes[i]));
    }

    for (int i = 0; i < small_box_meshes.size(); ++i) {

        small_box_models.push_back(new Model(materials["Wooden_box_2"], textures["Wooden_box_2"][0], textures["Wooden_box_2"][1],
                                             textures["Wooden_box_2"][2], textures["Wooden_box_2"][3], small_box_meshes[i]));
    }

   
    for (int i = 0; i < brick_wall_meshes.size(); ++i) {
        brick_wall_models.push_back(new Model(materials["Brick_wall"], textures["Brick_wall"][0], textures["Brick_wall"][1],
                                        textures["Brick_wall"][2], textures["Brick_wall"][3], brick_wall_meshes[i]));
    }

    for (int i = 0; i < concrete_wall_meshes.size(); ++i) {

        concrete_wall_models.push_back(new Model(materials["Concrete_wall"], textures["Concrete_wall"][0], textures["Concrete_wall"][1],
                                        textures["Concrete_wall"][2], textures["Concrete_wall"][3], concrete_wall_meshes[i]));

    }

    for (int i = 0; i < stone_wall_meshes.size(); ++i) {

        stone_wall_models.push_back(new Model(materials["Stone_tile"], textures["Stone_tile"][0], textures["Stone_tile"][1],
                                              textures["Stone_tile"][2], textures["Stone_tile"][3], stone_wall_meshes[i]));

    }


}

void Game::initShaders() {

    core_program = new Shader("vertex_shader.glsl", "fragment_shader.glsl", "");

}

void Game::framebuffer_resize_callback(GLFWwindow* window, int fbW, int fbH) {

    glViewport(0, 0, fbW, fbH);

} 

Game::Game(const char* title, const int width, const int height, const int& GLmajorVer, 
           const int& GLminorVer, bool resizable) : WINDOW_WIDTH(width), WINDOW_HEIGHT(height),
                                                    GL_VERSION_MAJOR(GLmajorVer), GL_VERSION_MINOR(GLminorVer),
                                                    camera(glm::vec3(0.f, -2.0f, -1.0f), 
                                                           glm::vec3(0.f, 0.f, 1.f), 
                                                           glm::vec3(0.f, 1.f, 0.f)) {
    
    window = nullptr;
    framebufferWidth = WINDOW_WIDTH;
    framebufferHeight = WINDOW_HEIGHT;

    camPosition = glm::vec3(0.0f, 0.0f, 2.0f);
    worldUp = glm::vec3(0.0f, 1.0f, 0.0f);
    camFront = glm::vec3(0.0f, 0.0f, -1.0f);
    
    fov = 90.0f;
    nearPlane = 0.1f;
    farPlane = 1000.0f;
    ProjectionMatrix = glm::mat4(1.0f);

    dt = 0.0f;
    curTime = 0.0f;
    lastTime = 0.0f;

    lastMouseX = 0.0f;
    lastMouseY = 0.0f;
    mouseX = 0.0f;
    mouseY = 0.0f;
    mouseOffsetX = 0.0f;
    mouseOffsetY = 0.0f;
    firstMouse = true;

    initGLFW();
    initWindow(title, resizable);
    initGLEW();
    initOpenGLOptions();
    initMatrices();
    initShaders();
    initTextures();
    initMaterials();
    initMeshes();
    initLights();
    initUniforms();
    initModels();

}

Game::~Game() {

    glfwDestroyWindow(window);
    glfwTerminate();
    
    delete core_program;

    for (auto& pair : textures) {

   //     pair.second->clear();
   //     delete pair;

    }


    for (int i = 0; i < materials.size(); ++i) {

    //    delete materials[i];

    }

    for (int i = 0; i < floor_tile_meshes.size(); ++i) {

        delete floor_tile_meshes[i];

    }    
}

void Game::initGLFW() {

    if (glfwInit() == GLFW_FALSE) {

        std::cout << "ERROR::GLFW_INIT_FAILED\n";
        glfwTerminate();

    }

}

void Game::initGLEW() {

    // init glew 
    glewExperimental = GL_TRUE;

    //Error check
    if (glewInit() != GLEW_OK) {
        
        std::cout << "ERROR::MAIN.CPP::GLEW_INIT_FAILED\n"; 
        glfwTerminate();

    }
   
}

void Game::initOpenGLOptions() {

    glEnable(GL_DEPTH_TEST);
    
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glFrontFace(GL_CCW);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

   glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

}

void Game::initMatrices() {

    ViewMatrix = glm::mat4(1.0f);
    ViewMatrix = glm::lookAt(camPosition, camPosition + camFront, worldUp);
    
    ProjectionMatrix = glm::perspective(
        glm::radians(fov),
        (float)(framebufferWidth) / framebufferHeight,
        nearPlane,
        farPlane
    );

}

int Game::getWindowShouldClose() {
    
    return glfwWindowShouldClose(window);

}

void Game::setWindowShouldClose() {

    glfwSetWindowShouldClose(window, GLFW_TRUE);

}


void Game::updateDt() {

    curTime = (float)glfwGetTime();
    dt = curTime - lastTime;
    lastTime = curTime;

}


void Game::updateUniforms() {


    ViewMatrix = camera.getViewMatrix();
    core_program->setMat4fv(ViewMatrix, "ViewMatrix");
    core_program->setVec3f(camera.getPosition(), "cameraPos");

    lightPos = camera.getPosition();
    core_program->setVec3f(lightPos, "lightPos0");

    glfwGetFramebufferSize(window, &framebufferWidth, &framebufferHeight);

    ProjectionMatrix = glm::perspective(
        glm::radians(fov),
        (float)framebufferWidth / framebufferHeight,
        nearPlane,
        farPlane
    );
    
    core_program->setMat4fv(ProjectionMatrix, "ProjectionMatrix");

}

void Game::update() {


    updateDt();
    updateInput();

}

void Game::render() {

        //Update

        //clear
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT );
        

        updateUniforms();

        

        for (int i = 0; i < floor_tile_models.size(); ++i) {
    
            floor_tile_models[i]->render(core_program);

        }

        for (int i = 0; i < big_box_models.size(); ++i) {

            big_box_models[i]->render(core_program);

        }

        for (int i = 0; i < small_box_models.size(); ++i) {

            small_box_models[i]->render(core_program);

        }

        for (int i = 0; i < concrete_wall_models.size(); ++i) {

            concrete_wall_models[i]->render(core_program);

        }


        for (int i = 0; i < brick_wall_models.size(); ++i) {

            brick_wall_models[i]->render(core_program);

        }


        for (int i = 0; i < stone_wall_models.size(); ++i) {

            stone_wall_models[i]->render(core_program);

        }


        // End
        glfwSwapBuffers(window);
        glFlush();


        glBindVertexArray(0);
        glUseProgram(0);
        glActiveTexture(0);
        glBindTexture(GL_TEXTURE_2D, 0);

}



