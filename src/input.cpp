#include "input.h"
#include "./system/window_manager.h"
#include "../include/GLFW/glfw3.h"


bool input::get_key(int key){
    return window_manager::keyStates[key] == GLFW_PRESS || window_manager::keyStates[key] == GLFW_REPEAT;
};
bool input::get_key_up(int key){
    return window_manager::keyStates[key] == GLFW_RELEASE;
};
bool input::get_key_down(int key){
    return window_manager::keyStates[key] == GLFW_PRESS;
};

float input::get_mouse_delta_x(){
    return window_manager::mouse_delta_x;
};
float input::get_mouse_delta_y(){
    return window_manager::mouse_delta_y;
};