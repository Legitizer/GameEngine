#version 330 core

layout (location = 0) in vec3 vPos;
uniform mat4 model;
uniform mat4 perspective;

void main(){
    gl_Position = model * vec4(vPos.x, vPos.y, vPos.z, 1.0);
}