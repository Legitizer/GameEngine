#ifndef _COMPONENT_H
#define _COMPONENT_H

class object;

class component {
public:
    virtual void on_update(){};
    object *parent;
private:

};

#endif