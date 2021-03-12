#version 330 core

layout (location = 0) in vec3 vPos;
layout (location = 1) in vec3 vNorm;

uniform mat4 model;
uniform mat4 view;
uniform mat4 perspective;

out vec3 worldNorm;
out vec3 worldPos;

void main(){
    worldPos = vec3(model * vec4(vPos.x, vPos.y, vPos.z, 1.0));
    worldNorm = normalize(vec3(model * vec4(vNorm, 0)).xyz);
    gl_Position = perspective * view * vec4(worldPos, 1.0);
}