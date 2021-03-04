#ifndef _Mesh_H
#define _Mesh_H

#include "../include/glm/vec3.hpp"
#include "../include/GL/glew.h"
#include "Shader.h"
#include <iostream>

class Object;

class Mesh {
private:
    GLuint vao_, positions_vbo_, ebo_;

    float *vertices_;
    int sizeof_vertices_;
    unsigned int *elements_;
    int sizeof_elements_;

    glm::vec3 pos, rot;
    glm::mat4 model, pers;

    Shader *shader;

    Object *parent;
public:
    Mesh(float *vertices, int sizeof_vertices_,  unsigned int *elements, int sizeof_elements_);
    ~Mesh();

    void initialize_vertex_arrays_();

    void set_shader(Shader *shader);
    void set_parent(Object *p);
    void draw();
};

#endif