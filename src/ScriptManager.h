#ifndef _ScriptManager_H
#define _ScriptManager_H

#include "Mesh.h"
#include "Object.h"

class ScriptManager{
private:
    Object terrain;
public:
    void start();
    void update();
    ~ScriptManager();
};

#endif