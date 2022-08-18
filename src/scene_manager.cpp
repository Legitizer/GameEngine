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

object *mo;

void scene_manager::start(){
    float *vertices = new float[12]{ 0.5f, 0.5f, 0.f,
                                    -0.5f, 0.5f, 0.f,
                                    -0.5f, -0.5f, 0.f,
                                    0.5f, -0.5f, 0.f};
    unsigned int *faces = new unsigned int[6]{   0, 1, 3,
                                                    1, 3, 2 };

    //mesh *m4 = mesh::get_mesh_from_obj("./src/meshes/cubeS.obj");
    mesh *m = mesh::get_mesh_from_obj("./src/meshes/cube.obj");
    mesh *m2 = mesh::get_mesh_from_obj("./src/meshes/sword.obj");
    mesh *m3 = mesh::get_mesh_from_obj("./src/meshes/monkeyS.obj");

    shader *s = new shader("./src/shaders/sources/default_shader.vert", "./src/shaders/sources/default_shader.frag");
    m->set_shader(s);
    m2->set_shader(s);
    m3->set_shader(s);
    //m4->set_shader(s);
 
    mo = new object();
    mo->add_component((component*) m);

    object *so = new object();
    so->add_component((component*) m2);

    object *co = new object();
    co->add_component((component*) m3);

    object *sco = new object();
    //sco->add_component((component*) m4);

    mo->transform->position = glm::vec3(0, 0, -2.f);
    so->transform->position = glm::vec3(2.f, 0, -2.f);
    co->transform->position = glm::vec3(-2.f, 0, -2.f);
    sco->transform->position = glm::vec3(-4, 0, -2.f);

    scene1->add_object(mo);
    scene1->add_object(so);
    scene1->add_object(co);
    scene1->add_object(sco);
}

void scene_manager::update(){
    scene1->update();

    if (input::get_key(GLFW_KEY_W)) {
        scene1->mainCamera->object->transform->position = scene1->mainCamera->object->transform->position + scene1->mainCamera->object->transform->forward * -0.01f;
    } else if (input::get_key(GLFW_KEY_S)) {
        scene1->mainCamera->object->transform->position = scene1->mainCamera->object->transform->position + scene1->mainCamera->object->transform->forward * 0.01f;
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

    scene1->mainCamera->object->transform->rotation = scene1->mainCamera->object->transform->rotation + glm::vec3(input::get_mouse_delta_y()*0.002f, input::get_mouse_delta_x()*0.002f, 0);
    if (scene1->mainCamera->object->transform->rotation.x > glm::radians(85.f)) {
        scene1->mainCamera->object->transform->rotation.x = glm::radians(85.f);
    } else if (scene1->mainCamera->object->transform->rotation.x < glm::radians(-85.f)) {
        scene1->mainCamera->object->transform->rotation.x = glm::radians(-85.f);
    }

    if (input::get_key_down(GLFW_KEY_M)) {
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    }else if (input::get_key_down(GLFW_KEY_N)) {
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }

    mo->transform->rotation = mo->transform->rotation + glm::vec3(0, 0.003f, 0.001f);

}

scene_manager::~scene_manager(){
    delete scene1;
}