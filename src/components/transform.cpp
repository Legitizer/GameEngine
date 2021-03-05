#include "transform.h"
#include "../../include/glm/ext.hpp"

transform::transform(glm::vec3 *position, glm::vec3 *rotation, glm::vec3 *scale){
    this->position = position;
    this->rotation = rotation;
    this->scale = scale;
}

void transform::apply_transformations(){
    //Rotate
    model = glm::rotate(glm::mat4(1.0f), this->rotation->x, glm::vec3(1, 0, 0));
    model = glm::rotate(model, this->rotation->y, glm::vec3(0, 1, 0));
    model = glm::rotate(model, this->rotation->z, glm::vec3(0, 0, 1));

    // Translate
    model = glm::translate(model, *(this->position));
}

transform::~transform(){
    delete position, rotation, scale;
}