#ifndef _Object_H
#define _Object_H

#include "../include/glm/vec3.hpp"
#include <vector>

class Mesh;
class Object {
public:
    Object();
    ~Object();
    void update();

    glm::vec3 position, rotation, scale;
    Mesh *mesh;
};

#endif