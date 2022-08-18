#include "window_manager.h"
#include <iostream>

window_manager::window_manager(int width, int height, const char* title){
    this->width_ = width;
    this->height_ = height;
    this->title_ = title;

    window_thread_ = new std::thread(create_window_, this);
}

int *window_manager::keyStates = new int[349]{};
void window_manager::key_call_back(GLFWwindow* window, int key, int scancode, int action, int mods){
    keyStates[key] = action;
}

double window_manager::mouse_delta_x = 0;
double window_manager::mouse_delta_y = 0;
double window_manager::mouse_pos_x = 0;
double window_manager::mouse_pos_y = 0;
double window_manager::prev_mouse_pos_x = 0;
double window_manager::prev_mouse_pos_y = 0;
void window_manager::mouse_call_back(){
    mouse_delta_x = prev_mouse_pos_x - mouse_pos_x;
    mouse_delta_y = prev_mouse_pos_y - mouse_pos_y;
    prev_mouse_pos_x = mouse_pos_x;
    prev_mouse_pos_y = mouse_pos_y;
}

window_manager::~window_manager(){
    if (window_ != NULL) {
        glfwDestroyWindow(window_);
    }
    if (title_ != NULL) {
        delete title_;
    }
}

int window_manager::create_window_() {
    int glfw_initialize_code = initialize_glfw_();

    if (glfw_initialize_code != 0) {
        std::cout << "GLFW has failed to initialize. Error code: " << glfw_initialize_code << std::endl;
        return 1;
    }

    this->window_ = glfwCreateWindow(this->width_, this->height_, this->title_, NULL, NULL);
    //Check if window was created successfully.
    if (this->window_ == NULL) {
        std::cout << "Window: '" << this->title_ << "' has failed to initialize" << std::endl;
        return 2;
    }

    glfwMakeContextCurrent(this->window_);
    glfwSetKeyCallback(window_, key_call_back);
    glfwSetInputMode(window_, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glewInit();
    glViewport(0, 0, width_, height_);
    glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);

    glClearColor(0,128/255.0f,128/255.0f, 1.0f);
    scene_manager = new class scene_manager(this);
    scene_manager->start();
    // Update loop until window is closed.
    while (!glfwWindowShouldClose(window_)) {
        update_();
    }
    glfwTerminate();
    delete scene_manager;
    return 0;
}

void window_manager::update_(){
    glfwPollEvents();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glfwGetCursorPos(window_, &mouse_pos_x, &mouse_pos_y);
    mouse_call_back();

    scene_manager->update();
    glfwSwapBuffers(window_);
}

void window_manager::wait_until_closed(){
    window_thread_->join();
}

int window_manager::initialize_glfw_(){
    if (initialized_) {
        return 0;
    }
    
    int glfw_status = glfwInit();
    // Check if glfw initialized correctly
    if (glfw_status == 0) {
        return 1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    initialized_ = 1;

    return 0;
}

int window_manager::get_width(){
    return width_;
};
int window_manager::get_height(){
    return height_;
};