#pragma once 

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
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
#include "Cube.h"
#include "RectCuboid.h"
#include "Plane.h"
#include "Model.h"
#include "Camera.h"
#include "Game.h"


class Game {

    public:
        Game(const char* title, const int width, const int height,
             const int& GLmajorVer, const int& GLminorVer, bool resizable);            
        ~Game();
        int getWindowShouldClose();
        void setWindowShouldClose();

        void render();
        void update();

        void updateInput();
        void updateKeyboardInput();
        void updateMouseInput();
        void updateDt();

    private:
        static void framebuffer_resize_callback(GLFWwindow* window, int fbW, int fbH);        

        void initWindow(const char* title, const bool& resizable);
        void initGLFW();
        void initGLEW();
        void initOpenGLOptions();
        void initMatrices();
        void initShaders();
        void initTextures();
        void initMaterials();
        void initMeshes();
        void initModels();
        void initLights();
        void initUniforms();
        
        void updateUniforms();

    private:
        GLFWwindow* window;
        Camera camera;
        const int WINDOW_WIDTH;
        const int WINDOW_HEIGHT;
        int framebufferWidth;
        int framebufferHeight;
        

        // Mouse time
        float dt;
        float curTime;
        float lastTime;

        // Mouse input
        double lastMouseX;
        double lastMouseY;
        double mouseX;
        double mouseY;
        double mouseOffsetX;
        double mouseOffsetY;
        bool firstMouse;

        glm::mat4 ViewMatrix;
        glm::vec3 camPosition;
        glm::vec3 worldUp;
        glm::vec3 camFront;

        glm::mat4 ProjectionMatrix;
        float fov;
        float nearPlane;
        float farPlane;
    
        Shader* core_program;
        std::map<std::string, std::vector<Texture*>> textures;
        std::map<std::string, Material*> materials;
        std::vector<Model*> floor_tile_models;
        std::vector<Model*> big_box_models;
        std::vector<Model*> small_box_models;
        std::vector<Model*> concrete_wall_models;
        std::vector<Model*> stone_wall_models;
        std::vector<Model*> brick_wall_models;


        std::vector<Mesh*> floor_tile_meshes;
        std::vector<Mesh*> big_box_meshes;
        std::vector<Mesh*> small_box_meshes;
        std::vector<Mesh*> concrete_wall_meshes;
        std::vector<Mesh*> stone_wall_meshes;
        std::vector<Mesh*> brick_wall_meshes;

        glm::vec3 lightPos;

        const int GL_VERSION_MAJOR;
        const int GL_VERSION_MINOR;

};
