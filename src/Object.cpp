#include "object.h"
#include "./components/mesh.h"

void object::update(){
    for (short i = 0; i < components.size(); i++) {
        components[i]->on_update();
    }
}

object::object(){

}

object::~object(){
    for (short i = 0; i < components.size(); i++) {
        delete components[i];
    }
}

void object::add_component(component *comp) {
    components.push_back(comp);
}