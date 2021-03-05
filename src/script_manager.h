#ifndef _scriptmanager_H
#define _scriptmanager_H

#include "Mesh.h"
#include "Object.h"

class script_manager{
private:
    object terrain;
public:
    void start();
    void update();
    ~script_manager();
};

#endif