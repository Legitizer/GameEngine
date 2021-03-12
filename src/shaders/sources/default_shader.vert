#version 330 core

layout (location = 0) in vec3 vPos;
layout (location = 1) in vec3 vNorm;

uniform mat4 model;
uniform mat4 view;
uniform mat4 perspective;

out vec3 norm;
out vec3 worldPos;

void main(){
    gl_Position = perspective * view * model * vec4(vPos.x, vPos.y, vPos.z, 1.0);
    norm = normalize(vNorm);
    worldPos = (model * vec4(vPos.x, vPos.y, vPos.z, 1.0)).xyz;
}