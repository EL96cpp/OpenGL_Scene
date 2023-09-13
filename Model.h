#pragma once

#include <iostream>

#include "Mesh.h"
#include "Texture.h"
#include "Material.h"
#include "Shader.h"

class Model {

    public:
        Model(Material* material, Texture* textureDiffuse, 
              Texture* textureSpecular, Texture* textureNormal,
              Texture* textureHeight, Mesh* mesh);
        
        ~Model();
        
        void update();
        void render(Shader* core_program);        

    private:
        void updateUniforms();

    public:
        Material* material;
        Texture* textureDiffuse;
        Texture* textureSpecular;
        Texture* textureNormal;
        Texture* textureHeight;
        Mesh* mesh;
    
};

