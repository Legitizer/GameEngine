#include "Mesh.h"
#include "Object.h"
#include "../include/glm/glm.hpp"
#include "../include/glm/ext.hpp"
#include "../include/glm/gtx/string_cast.hpp"

Mesh::Mesh(float *vertices, int sizeof_vertices_,  unsigned int *elements, int sizeof_elements_){
    this->vertices_ = vertices;
    this->elements_ = elements;

    this->sizeof_vertices_ = sizeof_vertices_;
    this->sizeof_elements_ = sizeof_elements_;

    pos = glm::vec3(0.f, 0.f, -1.f);
    rot = glm::vec3(0.f, 0.f, 0.f);

    model = glm::mat4(1.0f);
    model = glm::translate(model, pos);

    pers = glm::perspective(glm::radians(80.f), 800/600.f, 0.01f, 1000.f);

    if (vertices_ != NULL && elements_ != NULL) {
        initialize_vertex_arrays_();
    }
}

void Mesh::initialize_vertex_arrays_(){
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

void Mesh::set_shader(Shader *shader) {
    this->shader = shader;
}

void Mesh::draw(){
    shader->use();
    shader->set_mat4_uniform("model", model);
    shader->set_mat4_uniform("perspective", pers);

    glBindVertexArray(vao_);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo_);
    glDrawElements(GL_TRIANGLES, sizeof_elements_, GL_UNSIGNED_INT, NULL);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    
}

void Mesh::set_parent(Object *p){
    parent = p;
    parent->mesh = this;
}

Mesh::~Mesh(){
    delete shader;
    delete vertices_;
    delete elements_;
}