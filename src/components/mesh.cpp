#include "mesh.h"
#include "../scenes/scene.h"
#include "camera.h"
#include "transform.h"
#include "../object.h"
#include "../../include/glm/glm.hpp"
#include "../../include/glm/ext.hpp"
#include "../../include/glm/gtx/string_cast.hpp"
#include "../system/systemfile_manager.h"
#include <vector>
#include <iostream>

mesh::mesh(float *vertices, int sizeof_vertices_,  unsigned int *faces, int sizeof_faces_, float *normals, int sizeof_normals_){
    this->vertices_ = vertices;
    this->faces_ = faces;
    this->normals_ = normals;

    std::cout << sizeof_normals_ << std::endl;

    this->sizeof_vertices_ = sizeof_vertices_;
    this->sizeof_faces_ = sizeof_faces_;
    this->sizeof_normals_ = sizeof_normals_;

    if (vertices_ != NULL && faces_ != NULL && normals_ != NULL) {
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
            glBufferData(GL_ARRAY_BUFFER, sizeof_vertices_ * sizeof(float) * 3, vertices_, GL_STATIC_DRAW);

            glEnableVertexAttribArray(0);
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);

        if (normals_ != NULL) {
            glGenBuffers(1, &normals_vbo_);
            glBindBuffer(GL_ARRAY_BUFFER, normals_vbo_);
                glBufferData(GL_ARRAY_BUFFER, sizeof_normals_ * sizeof(float) * 3, normals_, GL_STATIC_DRAW);

                glEnableVertexAttribArray(1);
                glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);
            glBindBuffer(GL_ARRAY_BUFFER, 0);
        }

        // Index/Element Array Buffer
        glGenBuffers(1, &ebo_);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo_);
            glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof_faces_ * sizeof(unsigned int) * 3, faces_, GL_STATIC_DRAW);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void mesh::set_shader(shader *shaderToUse) {
    this->shaderToUse = shaderToUse;
}

void mesh::draw(){
    assert(shaderToUse != NULL);
    assert(object != NULL);
    assert(object->scene != NULL);
    
    shaderToUse->use();

    glm::mat4 model = (object->transform->model);
    shaderToUse->set_mat4_uniform("model", model);

    glm::mat4 view = (object->scene->mainCamera->view);
    shaderToUse->set_mat4_uniform("view", view);
    //std::cout << glm::to_string(model) << std::endl;

    glm::mat4 perspective = (object->scene->mainCamera->perspective);
    shaderToUse->set_mat4_uniform("perspective", perspective);
    
    glBindVertexArray(vao_);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo_);
    glDrawElements(GL_TRIANGLES, sizeof_faces_ * 3, GL_UNSIGNED_INT, NULL);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    
}

void mesh::on_update(){
    draw();
}

mesh::~mesh(){
    delete shaderToUse;
    delete vertices_;
    delete faces_;
}

mesh* mesh::get_mesh_from_obj(const char* filePath) {
    int number_of_vertices = 0, number_of_faces = 0;
    std::vector<float*> verticesV;
    std::vector<unsigned int*> facesV;
    std::vector<float*> normalsV; std::vector<int*> normalsIndicesV;

    std::string *file_text = new std::string();
    std::ifstream f(filePath);
    //Reading file to string.
    std::string line;
    while(std::getline(f, line)) {
        //v
        if (line.size() >= 3 && line.at(0) == 'v' && line.at(1) == ' ') {
            short charPointer = 1;
            float *v = new float[3]{0};
            for (short i = 0; i < 3; i++) {
                std::string s = "";
                charPointer += 1;
                
                try {
                    while (line.at(charPointer) != ' ' && line.at(charPointer) != '\n' && line.at(charPointer) != '\0') {
                        s += line.at(charPointer);
                        charPointer += 1;
                    }
                } catch (std::out_of_range e) {}
                
                float p = std::stof(s);
                v[i] = p;
            }
            verticesV.push_back(v);
        }

        //f
        if (line.size() >= 3 && line.at(0) == 'f' && line.at(1) == ' ') {
            short charPointer = 1;
            unsigned int *f = new unsigned int[3]{0};
            for (short i = 0; i < 3; i++) {
                short slashNumber = 0;
                std::string s = "";
                std::string normalIndex = "";

                charPointer += 1;
                try {
                    //Repeat until we reach the first slash /.
                    while (line.at(charPointer) != '/') {
                        s += line.at(charPointer);
                        charPointer += 1;
                    }
                    // Then repeat until we reach a space character
                    while (line.at(charPointer) != ' ') {
                        charPointer += 1;
                    }
                } catch (std::out_of_range e) {}
                
                unsigned int ui = std::stoi(s);
                f[i] = ui - 1;
            }
            facesV.push_back(f);
        }

        //vn
        if (line.size() >= 4 && line.at(0) == 'v' && line.at(1) == 'n' && line.at(2) == ' ') {
            short charPointer = 2;
            float *n = new float[3]{0};

            for (short i = 0; i < 3; i++) {
                std::string s = "";
                charPointer += 1;
                
                try {
                    while (line.at(charPointer) != ' ' && line.at(charPointer) != '\n' && line.at(charPointer) != '\0') {
                        s += line.at(charPointer);
                        charPointer += 1;
                    }
                } catch (std::out_of_range e) {}

                float p = std::stof(s);
                n[i] = p;
            }
            normalsV.push_back(n);
        }

        //ni
        if (line.size() >= 3 && line.at(0) == 'f' && line.at(1) == ' ') {
            short charPointer = 1;
            int *ns = new int[3]{0};

            for (short i = 0; i < 3; i++) {
                short slashNumber = 0;
                std::string normalIndex = "";

                charPointer += 1;
                try {
                    //Repeat until we reach the first slash /.
                    while (line.at(charPointer) != ' ') {
                        if (line.at(charPointer) == '/') {
                            slashNumber++;
                        }
                        charPointer += 1;
                        if (slashNumber == 2 && line.at(charPointer) != ' ') {
                            normalIndex += line.at(charPointer);
                        }
                    }
                } catch (std::out_of_range e) {}
                
                int ni = std::stoi(normalIndex);
                ns[i] = ni - 1;
            }
            normalsIndicesV.push_back(ns);
        }
    }
    f.close();

    //Turn vectors into arrays
    float *vertices = new float[verticesV.size()*3]{0};
    number_of_vertices = verticesV.size();
    for (int a = 0; a < verticesV.size(); a++) {
        for (int i = 0; i < 3; i++) {
            vertices[a*3 + i] = verticesV[a][i];
            vertices[a*3 + i] = verticesV[a][i];
            vertices[a*3 + i] = verticesV[a][i];
        }
        delete verticesV[a];
    }

    
    unsigned int *faces = new unsigned int[facesV.size()*3]{0};
    number_of_faces = facesV.size();
    for (int a = 0; a < facesV.size(); a++) {
        for (int i = 0; i < 3; i++) {
            faces[a*3 + i] = facesV[a][i];
            faces[a*3 + i] = facesV[a][i];
            faces[a*3 + i] = facesV[a][i];
        }
        delete facesV[a];
    }

    float *normals = new float[normalsIndicesV.size()*3*3]{0};

    for (int a = 0; a < normalsIndicesV.size(); a++) {
        int *nI = normalsIndicesV[a];
        
        normals[a*9 + 0] = normalsV[nI[0]][0];
        normals[a*9 + 1] = normalsV[nI[0]][1];
        normals[a*9 + 2] = normalsV[nI[0]][2];

        normals[a*9 + 3] = normalsV[nI[1]][0];
        normals[a*9 + 4] = normalsV[nI[1]][1];
        normals[a*9 + 5] = normalsV[nI[1]][2];

        normals[a*9 + 6] = normalsV[nI[2]][0];
        normals[a*9 + 7] = normalsV[nI[2]][1];
        normals[a*9 + 8] = normalsV[nI[2]][2];

        //std::cout << normals[a*9 + 0] << " " << normals[a*9 + 1] << " " << normals[a*9 + 2] << std::endl;
        //std::cout << normals[a*9 + 3] << " " << normals[a*9 + 4] << " " << normals[a*9 + 5] << std::endl;
        //std::cout << normals[a*9 + 6] << " " << normals[a*9 + 7] << " " << normals[a*9 + 8] << std::endl;

        delete normalsIndicesV[a];
    }
    for (int a = 0; a < normalsV.size(); a++) {
        //std::cout << normalsV[a][0] << " " << normalsV[a][1] << " " << normalsV[a][2] << std::endl;
        delete normalsV[a];
    }

    mesh *m = new mesh(vertices, number_of_vertices, faces, number_of_faces, normals, normalsIndicesV.size()*3);
    return m;
};