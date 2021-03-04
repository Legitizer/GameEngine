#include "Shader.h"

#include "SystemFileManager.h"
#include "../include/GL/glew.h"
#include <iostream>

Shader::Shader(const char* vertex_shader_filename, const char* fragment_shader_filename){
    program = glCreateProgram();

    if (vertex_shader_filename != NULL) {
        vertex_shader = glCreateShader(GL_VERTEX_SHADER);

        const char* vertex_shader_source = SystemFileManager::read_file(vertex_shader_filename);
        glShaderSource(vertex_shader, 1, &vertex_shader_source, NULL);

        glCompileShader(vertex_shader);
        glAttachShader(program, vertex_shader);
    }

    if (fragment_shader_filename != NULL) {
        fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);

        const char* fragment_shader_source = SystemFileManager::read_file(fragment_shader_filename);
        glShaderSource(fragment_shader, 1, &fragment_shader_source, NULL);

        glCompileShader(fragment_shader);
        glAttachShader(program, fragment_shader);
    }
    glLinkProgram(program);
}

void Shader::use(){
    glUseProgram(program);
}

void Shader::set_mat4_uniform(const char* name_of_uniform, glm::mat4 m){
    int loc = glGetUniformLocation(program, name_of_uniform);
    glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(m));
}