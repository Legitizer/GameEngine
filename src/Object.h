#ifndef _object_H
#define _object_H

#include "../include/glm/vec3.hpp"
#include "./components/component.h"
#include <vector>

class object {
public:
    object();
    ~object();
    void update();

    void add_component(component *comp);

private:
    std::vector<component*> components;
};

#endif