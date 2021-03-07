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


public:
    window_manager(int width, int height, const char* title);
    ~window_manager();

    int get_width();
    int get_height();

    void wait_until_closed();
};

#endif