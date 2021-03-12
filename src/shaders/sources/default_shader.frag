#version 330 core

in vec3 norm;
in vec3 worldPos;

out vec4 frag_color;

void main(){
    //frag_color = vec4(brightness, brightness, brightness, 1.0);
    frag_color = vec4(0, (norm.x + 1)/2, 0, 1.0);
}