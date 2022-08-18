#ifndef _camera_H
#define _camera_H

#include "component.h"
#include "../../include/glm/mat4x4.hpp"

class camera : public component {
public:
    glm::mat4 view;
    glm::mat4 perspective;

    camera() : camera(80.f, 800/600.f, 0.01f, 1000.f){};
    camera(float fov, float ratio, float nearP, float farP);

    void set_perspective(float fov, float ratio, float nearP, float farP);
    void on_update();
};

#endif