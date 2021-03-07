#version 330 core

layout (location = 0) in vec3 vPos;
uniform mat4 model;
uniform mat4 view;
uniform mat4 perspective;

void main(){
    gl_Position = perspective * view * model * vec4(vPos.x, vPos.y, vPos.z, 1.0);
}