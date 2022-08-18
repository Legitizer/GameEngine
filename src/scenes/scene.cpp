#include "scene.h"
#include "../system/window_manager.h"
#include "../object.h"
#include "../components/camera.h"
#include <iostream>

scene::scene(window_manager *windowManager) {
    this->windowManager = windowManager;
    start();
};

scene::~scene() {
    for (int i = 0; i < objects.size(); i++) {
        delete objects[i];
    }
};

void scene::start() {
    object *cameraObj = new object("cameraObj");
    mainCamera = new camera(glm::radians(80.f), (float)windowManager->get_width()/windowManager->get_height(), 0.01f, 1000.f);
    cameraObj->add_component(mainCamera);
    this->add_object(cameraObj);
};

void scene::update() {
    for (int i = 0; i < objects.size(); i++) {
        objects[i]->update();
    }
};

void scene::add_object(object *obj) {
    assert(obj != NULL);
    obj->scene = this;
    objects.push_back(obj);
};

object* scene::find_object(std::string label) {
    for (int i = 0; i < objects.size(); i++) {
        if (objects[i]->label.compare(label) == 0) {
            return objects[i];
        };
    }
    return 0;
};

