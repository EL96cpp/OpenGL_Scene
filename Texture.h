#pragma once

#include <iostream>
#include <string>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <SOIL/SOIL.h>

class Texture {

    public:
        Texture(const char* fileName, GLenum type);
        ~Texture();
        
        GLuint getID() const;
        void bind(const GLuint textureUnit);
        void unbind();

    private:
        GLuint id;
        int width;
        int height;
        unsigned int type;
};
