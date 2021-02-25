#ifndef _ScriptManager_H
#define _ScriptManager_H

#include "Mesh.h"

class ScriptManager{
private:
    Mesh *m;
public:
    void start();
    void update();
    ~ScriptManager();
};

#endif