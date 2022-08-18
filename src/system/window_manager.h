#ifndef _window_manager_H
#define _window_manager_H

#include "../../include/GL/glew.h"
#include "../../include/GLFW/glfw3.h"
#include "../scene_manager.h"
#include <thread>

class window_manager {
private:
    // Variables
    int initialized_;
    GLFWwindow *window_;
    std::thread *window_thread_;
    scene_manager *scene_manager;

    // Window properties
    int width_, height_;
    const char* title_;

    // Functions
    int initialize_glfw_();
    int create_window_();
    void update_();
    static void key_call_back(GLFWwindow* window, int key, int scancode, int action, int mods);
    static void mouse_call_back();

public:
    window_manager(int width, int height, const char* title);
    ~window_manager();

    static int *keyStates;

    static double prev_mouse_pos_x, mouse_pos_x, mouse_delta_x;
    static double prev_mouse_pos_y, mouse_pos_y, mouse_delta_y;

    int get_width();
    int get_height();

    void wait_until_closed();
};

#endif