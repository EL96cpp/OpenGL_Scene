#include "Model.h"

Model::Model(Material* material, Texture* textureDiffuse, 
             Texture* textureSpecular, Texture* textureNormal,
             Texture* textureHeight, Mesh* mesh) : material(material),
                                                   textureDiffuse(textureDiffuse),
                                                   textureSpecular(textureSpecular),
                                                   textureNormal(textureNormal),
                                                   textureHeight(textureHeight),
                                                   mesh(mesh) {}
        
Model::~Model() {

    

}


void Model::update() {



}

void Model::render(Shader* core_program) {

//    updateUniforms();

    material->sendToShader(*core_program);
        
    core_program->use();

    //Activate texture
    textureDiffuse->bind(0);    
    textureSpecular->bind(1);
    textureNormal->bind(2);
    textureHeight->bind(3);

    mesh->render(core_program);

}

void Model::updateUniforms() {



}
