#include "transform.h"
#include "../../include/glm/ext.hpp"

transform::transform(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale){
    this->position.x = position.x; this->position.y = position.y; this->position.z = position.z;
    this->rotation.x = rotation.x; this->rotation.y = rotation.y; this->rotation.z = rotation.z;
    this->scale.x = scale.x; this->scale.y = scale.y; this->scale.z = scale.z;
    apply_transformations();
}

void transform::apply_transformations(){
    // Translate
    model = glm::translate(glm::mat4(1.0f), (this->position));

    //Rotate
    model = glm::rotate(model, this->rotation.x, glm::vec3(1, 0, 0));
    model = glm::rotate(model, this->rotation.y, glm::vec3(0, 1, 0));
    model = glm::rotate(model, this->rotation.z, glm::vec3(0, 0, 1));

    forward = -glm::normalize(glm::vec3(model[2]));
    right = -glm::normalize(glm::vec3(model[0]));
    up = -glm::normalize(glm::vec3(model[1]));
}

void transform::on_update(){
    apply_transformations();
}

transform::~transform(){
    
}

