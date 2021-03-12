#ifndef _Mesh_H
#define _Mesh_H

#include "../../include/glm/vec3.hpp"
#include "../../include/GL/glew.h"
#include "component.h"
#include "../shaders/shader.h"
#include <iostream>

class object;

class mesh : public component{
private:
    GLuint vao_, positions_vbo_, normals_vbo_, ebo_;

    float *vertices_;
    int sizeof_vertices_;
    unsigned int *faces_;
    int sizeof_faces_;
    float *normals_;
    int sizeof_normals_;

    shader *shaderToUse;
public:
    mesh(float *vertices, int sizeof_vertices_,  unsigned int *faces, int sizeof_faces_, float *normals, int sizeof_normals_);
    ~mesh();

    void initialize_vertex_arrays_();

    void set_shader(shader *shaderToUse);
    void draw();

    void on_update();

    static mesh* get_mesh_from_obj(const char* filePath);
};

#endif