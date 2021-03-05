#ifndef _Mesh_H
#define _Mesh_H

#include "../include/glm/vec3.hpp"
#include "../include/GL/glew.h"
#include "../shaders/shader.h"
#include <iostream>

class object;

class mesh {
private:
    GLuint vao_, positions_vbo_, ebo_;

    float *vertices_;
    int sizeof_vertices_;
    unsigned int *elements_;
    int sizeof_elements_;

    shader *shaderToUse;
public:
    mesh(float *vertices, int sizeof_vertices_,  unsigned int *elements, int sizeof_elements_);
    ~mesh();

    void initialize_vertex_arrays_();

    void set_shader(shader *shaderToUse);
    void draw();
};

#endif