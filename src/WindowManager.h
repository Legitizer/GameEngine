#ifndef _WindowManager_H
#define _WindowManager_H

#include "../include/GL/glew.h"
#include "../include/GLFW/glfw3.h"
#include <thread>

class WindowManager {
private:
// Variables
int initialized_;
GLFWwindow *window_;
std::thread *window_thread_;

// Window properties
int width_, height_;
const char* title_;

// Functions
int initialize_glfw_();
int create_window_();
void update_();


public:
WindowManager(int width, int height, const char* title);
~WindowManager();
void wait_until_closed();
};

#endif