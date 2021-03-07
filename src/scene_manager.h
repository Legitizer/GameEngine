#ifndef _scene_manager_H
#define _scene_manager_H

#include "./components/mesh.h"
#include "object.h"
#include "./scenes/scene.h"

class scene_manager{
private:
    object terrain;
    scene *scene1;
public:
    void start();
    void update();
    scene_manager(window_manager *windowManager);
    ~scene_manager();
};

#endif