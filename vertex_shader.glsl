#version 330

layout (location = 0) in vec3 vertex_position;
layout (location = 1) in vec2 vertex_texcoord;
layout (location = 2) in vec3 vertex_normal;
layout (location = 3) in vec3 vertex_tangent;
layout (location = 4) in vec3 vertex_bitangent;

out vec3 vs_position;
out vec2 vs_texcoord;
out vec3 vs_normal;
out mat3 TBN;


uniform mat4 ModelMatrix;
uniform mat4 ViewMatrix;
uniform mat4 ProjectionMatrix;


void main() {

    vec3 T = normalize(vec3(ModelMatrix * vec4(vertex_tangent, 0.0)));
    vec3 B = normalize(vec3(ModelMatrix * vec4(vertex_bitangent, 0.0)));
    vec3 N = normalize(vec3(ModelMatrix * vec4(vertex_normal, 0.0)));
    TBN = mat3(T, B, N);

    vs_position = vec4(ModelMatrix * vec4(vertex_position, 1.0f)).xyz;
    vs_texcoord = vec2(vertex_texcoord.x, vertex_texcoord.y * -1.0f);
    vs_normal = mat3(ModelMatrix) * vertex_normal;

    gl_Position = ProjectionMatrix * ViewMatrix * ModelMatrix * vec4(vertex_position, 1.0f);

}
