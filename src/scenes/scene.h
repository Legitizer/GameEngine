#ifndef _scene_H
#define _scene_H

#include "../object.h"

#include <vector>
#include <string>

class camera;
class window_manager;
class scene {
public:
    window_manager *windowManager;
    camera *mainCamera;

    scene(window_manager *windowManager);
    ~scene();

    void add_object(object *obj);
    object* find_object(std::string label);

    void start();
    void update();
private:
    std::vector<object*> objects;
};

#endif