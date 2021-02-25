#ifndef _Mesh_H
#define _Mesh_H

#include "../include/glm/vec3.hpp"
#include "../include/GL/glew.h"
#include <iostream>

class Mesh {
private:
    GLuint vao_, positions_vbo_, ebo_;

    float *vertices_;
    int sizeof_vertices_;
    unsigned int *elements_;
    int sizeof_elements_;

public:
    Mesh(float *vertices, int sizeof_vertices_,  unsigned int *elements, int sizeof_elements_);
    void initialize_vertex_arrays_();
    void draw();
};

#endif