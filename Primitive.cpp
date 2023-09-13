#include "Primitive.h"

void Primitive::addTangentsAndBitangents() {

    for (int i = 0; i < vertices.size(); i += 4) {

        glm::vec3 e1 = vertices[i+1].position - vertices[i].position;
        glm::vec3 e2 = vertices[i+2].position - vertices[i].position;
        glm::vec2 dUV1 = vertices[i+1].texcoord - vertices[i].texcoord;
        glm::vec2 dUV2 = vertices[i+2].texcoord - vertices[i].texcoord;

        float f = 1.0f / (dUV1.x * dUV2.y - dUV2.x * dUV1.x);

        glm::vec3 tangent;
        glm::vec3 bitangent;
    
        tangent.x = f * (dUV2.y * e1.x - dUV1.y * e2.x);
        tangent.y = f * (dUV2.y * e1.y - dUV1.y * e2.y);
        tangent.z = f * (dUV2.y * e1.z - dUV1.y * e2.z);

        bitangent.x = f * (-dUV2.x * e1.x + dUV1.x * e2.x);
        bitangent.y = f * (-dUV2.x * e1.y + dUV1.x * e2.y);
        bitangent.z = f * (-dUV2.x * e1.z + dUV1.x * e2.z);

        vertices[i].tangent = tangent;
        vertices[i+1].tangent = tangent;
        vertices[i+2].tangent = tangent;
        vertices[i+3].tangent = tangent;

        vertices[i].bitangent = bitangent;
        vertices[i+1].bitangent = bitangent;
        vertices[i+2].bitangent = bitangent;
        vertices[i+3].bitangent = bitangent;

    }

}


void Primitive::set(const Vertex* vertices, const unsigned nrOfVertices,
                    const GLuint* indices, const unsigned nrOfIndices) {

    for (int i = 0; i < nrOfVertices; ++i) {

        
        this->vertices.push_back(vertices[i]);

    }

    
    addTangentsAndBitangents();


    for (int i = 0; i < nrOfIndices; ++i) {

        this->indices.push_back(indices[i]);

    }


}

Vertex* Primitive::getVertices() {

    return vertices.data();

}

GLuint* Primitive::getIndices() {

    return indices.data();

}


const unsigned Primitive::getNrOfVertices() {

    return vertices.size();

}


const unsigned Primitive::getNrOfIndices() {

    return indices.size();

}

