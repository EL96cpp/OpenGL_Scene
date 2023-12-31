#include "Texture.h"

Texture::Texture(const char* fileName, GLenum type) {

    this->type = type;

    unsigned char* image = SOIL_load_image(fileName, &width, &height, NULL, SOIL_LOAD_RGBA);
    
    glGenTextures(1, &id);
    glBindTexture(type, id);

    glTexParameteri(type, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(type, GL_TEXTURE_WRAP_T, GL_REPEAT);
//    glTexParameteri(type, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
//    glTexParameteri(type, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    if (image) {
    
        glTexImage2D(type, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
        glGenerateMipmap(type);

    } else {

        std::cout << "ERROR::TEXTURE::TEXTURE_LOADING_FAILED: " << fileName << "\n";

    }
    
    glActiveTexture(0);
    glBindTexture(type, 0);
    SOIL_free_image_data(image);
    
}



Texture::~Texture() {

    glDeleteTextures(1, &id);  

}

GLuint Texture::getID() const {
    
    return id;

}

void Texture::bind(const GLuint textureUnit) {

    glActiveTexture(GL_TEXTURE0 + textureUnit);
    glBindTexture(type, id);

}

void Texture::unbind() {

    glActiveTexture(0);
    glBindTexture(type, 0);

}


