#include "scene_manager.h"
#include "./components/transform.h"
#include "../include/glm/gtx/string_cast.hpp"

class window_manager;
scene_manager::scene_manager(window_manager *windowManager){
    scene1 = new scene(windowManager);
};

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
    scene1->add_object(&terrain);

    
}

void scene_manager::update(){
    terrain.update();

    terrain.transform->position = terrain.transform->position + glm::vec3(0, 0, -0.001f);
    terrain.transform->rotation = terrain.transform->rotation + glm::vec3(0, -0.005f, 0);
    terrain.transform->apply_transformations();
}

scene_manager::~scene_manager(){
    delete scene1;
}