#include "camera.h"
#include "../object.h"
#include "transform.h"
#include "../../include/glm/mat4x4.hpp"
#include "../../include/glm/glm.hpp"
#include "../../include/glm/ext.hpp"
#include "../../include/glm/gtx/string_cast.hpp"
#include <iostream>

camera::camera(float fov, float ratio, float nearP, float farP){
    this->perspective = glm::perspective(fov, ratio, nearP, farP);
};

void camera::set_perspective(float fov, float ratio, float nearP, float farP) {
    this->perspective = glm::perspective(fov, ratio, nearP, farP);
};

void camera::on_update(){
    //Rotate
    view = glm::inverse(object->transform->model);
}