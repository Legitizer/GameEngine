#include "ScriptManager.h"

void ScriptManager::start(){
    float *vertices = new float[12]{ 0.5f, 0.5f, 0.f,
                                    -0.5f, 0.5f, 0.f,
                                    -0.5f, -0.5f, 0.f,
                                    0.5f, -0.5f, 0.f};
    unsigned int *elements = new unsigned int[6]{   0, 1, 3,
                                                    1, 3, 2};
    
    m = new Mesh(vertices, 12, elements, 6);
}

void ScriptManager::update(){
    m->draw();
}

ScriptManager::~ScriptManager(){
    delete m;
}