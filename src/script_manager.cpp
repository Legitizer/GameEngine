#include "script_manager.h"

void script_manager::start(){
    glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
    float *vertices = new float[12]{ 0.5f, 0.5f, 0.f,
                                    -0.5f, 0.5f, 0.f,
                                    -0.5f, -0.5f, 0.f,
                                    0.5f, -0.5f, 0.f};
    unsigned int *elements = new unsigned int[6]{   0, 1, 3,
                                                    1, 3, 2 };

    mesh *m = new mesh(vertices, 3 * 4,  elements, 3 * 2);
    shader *s = new shader("./shaders/sources/default_shader.vert", "./shaders/sources/default_shader.frag");
    m->set_shader(s);
    terrain.add_component((component*) m);
}

void script_manager::update(){
    terrain.update();
}

script_manager::~script_manager(){

}