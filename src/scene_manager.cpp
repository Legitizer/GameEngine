#include "scene_manager.h"
#include "./system/window_manager.h"
#include "./components/transform.h"
#include "./components/camera.h"
#include "../include/glm/gtx/string_cast.hpp"
#include "input.h"

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
    terrain.transform->position = glm::vec3(0, 0, -2.f);
}

void scene_manager::update(){
    scene1->update();

    if (input::get_key(GLFW_KEY_W)) {
        scene1->mainCamera->object->transform->position = scene1->mainCamera->object->transform->position + scene1->mainCamera->object->transform->forward * 0.01f;
    } else if (input::get_key(GLFW_KEY_S)) {
        scene1->mainCamera->object->transform->position = scene1->mainCamera->object->transform->position + scene1->mainCamera->object->transform->forward * -0.01f;
    }
    if (input::get_key(GLFW_KEY_A)) {
        scene1->mainCamera->object->transform->position = scene1->mainCamera->object->transform->position + scene1->mainCamera->object->transform->right * -0.01f;
    } else if (input::get_key(GLFW_KEY_D)) {
        scene1->mainCamera->object->transform->position = scene1->mainCamera->object->transform->position + scene1->mainCamera->object->transform->right * 0.01f;
    }
    if (input::get_key(GLFW_KEY_SPACE)) {
        scene1->mainCamera->object->transform->position = scene1->mainCamera->object->transform->position + scene1->mainCamera->object->transform->up * 0.01f;
    } else if (input::get_key(GLFW_KEY_LEFT_CONTROL)) {
        scene1->mainCamera->object->transform->position = scene1->mainCamera->object->transform->position + scene1->mainCamera->object->transform->up * -0.01f;
    }

    scene1->mainCamera->object->transform->rotation = scene1->mainCamera->object->transform->rotation + glm::vec3(0, -input::get_mouse_delta_x()*0.002f, 0);
}

scene_manager::~scene_manager(){
    delete scene1;
}