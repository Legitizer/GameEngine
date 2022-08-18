#ifndef _transform_H
#define _transform_H

#include "../../include/glm/mat4x4.hpp"
#include "../../include/glm/vec3.hpp"
#include "component.h"

class transform : public component {
public:
    glm::mat4 model;
    glm::vec3 position, rotation, scale, forward, right, up;

    transform() : transform(glm::vec3(), glm::vec3(), glm::vec3()){};
    transform(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale);
    ~transform();

    void apply_transformations();
    void on_update();
private:

};

#endif