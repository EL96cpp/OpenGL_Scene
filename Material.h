#pragma once 

#include <iostream>
#include <fstream>
#include <string>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Shader.h"

class Material {

    public:
        Material(glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular,
                 GLint diffuseTex, GLint specularTex, GLint normalTex);
    
        ~Material();

        void sendToShader(Shader& program);

    private:
        glm::vec3 ambient;
        glm::vec3 diffuse;
        glm::vec3 specular;
        GLint diffuseTex;
        GLint specularTex;
        GLint normalTex;

};
