#version 330

struct Material {

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    sampler2D diffuseTex;
    sampler2D specularTex;
    sampler2D normalTex;
    sampler2D heightTex;

};

in vec3 vs_position;
in vec2 vs_texcoord;
in vec3 vs_normal;
in mat3 TBN;

out vec4 fs_color;

uniform Material material;

uniform vec3 lightPos0;
uniform vec3 cameraPos;


vec2 ParallaxMapping(Material material, vec2 texCoords, vec3 viewDir) {

    const float numLayers = 5;
    float layerDepth = 1.0 / numLayers;
    float currentLayerDepth = 0.0;

    float height = texture(material.heightTex, texCoords).r;
    vec2 P = viewDir.xy * 0.017;

//    vec2 p = viewDir.xy / viewDir.z * (height * 0.02);
    
    vec2 deltaTexCoords = P / numLayers;
    vec2 currentTexCoords = texCoords;
    float currentDepthMapValue = texture(material.heightTex, currentTexCoords).r;

    while (currentLayerDepth < currentDepthMapValue) {

        currentTexCoords -= deltaTexCoords;
        currentDepthMapValue = texture(material.heightTex, currentTexCoords).r;
        currentLayerDepth += layerDepth;

    }

    vec2 prevTexCoords = currentTexCoords + deltaTexCoords;
    
    float afterDepth = currentDepthMapValue - currentLayerDepth;
    float beforeDepth = texture(material.heightTex, prevTexCoords).r - currentLayerDepth + layerDepth; 

    float weight = afterDepth / (afterDepth - beforeDepth);
    vec2 finalTexCoords = prevTexCoords * weight + currentTexCoords * (1.0 - weight);

    return finalTexCoords;

}


vec3 calculateDiffuse(Material material, vec3 vs_position, vec3 vs_normal, vec3 lightPos0, vec2 vs_texcoord) {

    vec3 normal = normalize(texture(material.normalTex, vs_texcoord).xyz * 2.0 - 1.0);
    normal = normalize(TBN * normal);

    vec3 posToLightDirVec = normalize(lightPos0 - vs_position);
    float diffuse = clamp(dot(posToLightDirVec, normal), 0, 1);
    
    vec3 diffuseFinal = material.diffuse * diffuse;
    return diffuseFinal;

}


vec3 calculateSpecular(Material material, vec3 vs_position, vec3 vs_normal, vec3 lightPos0, vec3 cameraPos) {


    vec3 lightToPosDirVec = normalize(vs_position - lightPos0);
    vec3 reflectDirVec = normalize(reflect(lightToPosDirVec, vs_normal));
    vec3 posToViewDirVec = normalize(cameraPos - vs_position);
    float specularConstant = pow(max(dot(posToViewDirVec, reflectDirVec), 0), 100);
    vec3 specularFinal = material.specular * specularConstant * texture(material.specularTex, vs_texcoord).xyz;
    return specularFinal;

}



void main() {

    vec3 viewDir = normalize(TBN * (cameraPos - vs_position));
    
    vec2 texCoord = ParallaxMapping(material, vs_texcoord, viewDir); 

    //Ambient light
    vec3 ambientLight = material.ambient;

    //Diffuse light
    vec3 diffuseFinal = calculateDiffuse(material, vs_position, vs_normal, lightPos0, texCoord);

    //Specular light
    vec3 specularFinal = calculateSpecular(material, vs_position, vs_normal, lightPos0, cameraPos);

    //Attenuation


    //Final light
    fs_color = texture(material.diffuseTex, texCoord) *
               (vec4(ambientLight, 1.0f) + vec4(diffuseFinal, 1.0f) + vec4(specularFinal, 1.0f));

}
