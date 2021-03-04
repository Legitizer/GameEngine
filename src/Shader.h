#ifndef _Shader_H
#define _Shader_H

#include "../include/glm/mat4x4.hpp"
#include "../include/glm/gtc/type_ptr.hpp"

class Shader {
public:
    Shader(const char* vertex_shader_filename, const char* fragment_shader_filename);
    void use();

    void set_mat4_uniform(const char* name_of_uniform, glm::mat4 m);
private:
    unsigned int program, vertex_shader, fragment_shader;

    void make_shader(const char* shader_filename, int shader_type);
};

#endif