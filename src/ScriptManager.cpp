#include "ScriptManager.h"

void ScriptManager::start(){
    glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
    float *vertices = new float[12]{ 0.5f, 0.5f, 0.f,
                                    -0.5f, 0.5f, 0.f,
                                    -0.5f, -0.5f, 0.f,
                                    0.5f, -0.5f, 0.f};
    unsigned int *elements = new unsigned int[6]{   0, 1, 3,
                                                    1, 3, 2 };
    
    terrain = Object();

    Mesh *m = new Mesh(vertices, 12, elements, 6);
    m->set_shader(new Shader("default_shader.vert", "default_shader.frag"));
    m->set_parent(&terrain);
}

void ScriptManager::update(){
    terrain.update();
}

ScriptManager::~ScriptManager(){

}