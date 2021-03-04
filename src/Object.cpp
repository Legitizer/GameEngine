#include "Object.h"
#include "Mesh.h"

void Object::update(){
    if (mesh != NULL) {
        mesh->draw();
    }
}

Object::Object(){}

Object::~Object(){
    if (mesh != NULL) {
        delete mesh;
    }
}