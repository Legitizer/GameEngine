#include "object.h"
#include "./components/mesh.h"
#include "./components/transform.h"
#include <iostream>

void object::update(){
    for (short i = 0; i < components.size(); i++) {
        components[i]->on_update();
    }
}

object::object(){
    label = "object";
    transform = new class transform();
    add_component((component*)transform);
}

object::~object(){
    for (short i = 0; i < components.size(); i++) {
        delete components[i];
    }
}

void object::add_component(component *comp) {
    comp->object = this;
    components.push_back(comp);
}

template <class component_type> component_type* object::get_component() {
    for (short i = 0; i < components.size(); i++) {
        component_type *comp = dynamic_cast<component_type*>(components[i]);
        if (comp) {
            return comp;
        }
    }
    return 0;
}

template transform* object::get_component();