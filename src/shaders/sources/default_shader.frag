#version 330 core

in vec3 worldNorm;
in vec3 worldPos;

out vec4 frag_color;

void main(){
    float angle = dot(worldNorm, normalize(vec3(1,0.5,0.75)));
    float brightness = max(angle, 0.1);
    frag_color = vec4(brightness, brightness, brightness, 1.0);
    //frag_color = vec4(0, 1, 0, 1.0);
}