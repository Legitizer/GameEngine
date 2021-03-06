#include "scene_manager.h"
#include "./components/transform.h"
#include "../include/glm/gtx/string_cast.hpp"

void scene_manager::start(){
    //glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
    float *vertices = new float[12]{ 0.5f, 0.5f, 0.f,
                                    -0.5f, 0.5f, 0.f,
                                    -0.5f, -0.5f, 0.f,
                                    0.5f, -0.5f, 0.f};
    unsigned int *elements = new unsigned int[6]{   0, 1, 3,
                                                    1, 3, 2 };

    mesh *m = new mesh(vertices, 3 * 4,  elements, 3 * 2);

    shader *s = new shader("./src/shaders/sources/default_shader.vert", "./src/shaders/sources/default_shader.frag");
    m->set_shader(s);
 
    terrain.add_component((component*) m);
    //scene1.add_object(&terrain);
}

void scene_manager::update(){
    terrain.update();
}

scene_manager::~scene_manager(){
    
}