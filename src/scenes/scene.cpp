#include "scene.h"
#include <iostream>

scene::scene() {
    start();
};

scene::~scene() {
    for (int i = 0; i < objects.size(); i++) {
        delete objects[i];
    }
};

void scene::start() {
    
};

void scene::update() {
    for (int i = 0; i < objects.size(); i++) {
        objects[i]->update();
    }
};

void scene::add_object(object *obj) {
    assert(obj != NULL);
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

