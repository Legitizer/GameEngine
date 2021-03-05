#include "mesh.h"
#include "../object.h"
#include "../include/glm/glm.hpp"
#include "../include/glm/ext.hpp"
#include "../include/glm/gtx/string_cast.hpp"

mesh::mesh(float *vertices, int sizeof_vertices_,  unsigned int *elements, int sizeof_elements_){
    this->vertices_ = vertices;
    this->elements_ = elements;

    this->sizeof_vertices_ = sizeof_vertices_;
    this->sizeof_elements_ = sizeof_elements_;

    if (vertices_ != NULL && elements_ != NULL) {
        initialize_vertex_arrays_();
    }
}

void mesh::initialize_vertex_arrays_(){
    // Generates ONE vertex array object whos ID is stored in vao_.
    glGenVertexArrays(1, &vao_);
    glBindVertexArray(vao_);
        // Generates a vertex buffer object and stores its ID in positions_vbo_. This will be filled with vertex positions.
        glGenBuffers(1, &positions_vbo_);
        glBindBuffer(GL_ARRAY_BUFFER, positions_vbo_);
            glBufferData(GL_ARRAY_BUFFER, sizeof_vertices_ * sizeof(float), vertices_, GL_STATIC_DRAW);

            glEnableVertexAttribArray(0);
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);

        // Index/Element Array Buffer
        glGenBuffers(1, &ebo_);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo_);
            glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof_elements_ * sizeof(unsigned int), elements_, GL_STATIC_DRAW);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void mesh::set_shader(shader *shaderToUse) {
    this->shaderToUse = shaderToUse;
}

void mesh::draw(){
    shaderToUse->use();
    glBindVertexArray(vao_);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo_);
    glDrawElements(GL_TRIANGLES, sizeof_elements_, GL_UNSIGNED_INT, NULL);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    
}

mesh::~mesh(){
    delete shaderToUse;
    delete vertices_;
    delete elements_;
}