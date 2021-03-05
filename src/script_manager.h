#ifndef _scriptmanager_H
#define _scriptmanager_H

#include "./components/mesh.h"
#include "object.h"

class script_manager{
private:
    object terrain;
public:
    void start();
    void update();
    ~script_manager();
};

#endif