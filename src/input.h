#ifndef _input_h
#define _input_h

class input {
public:
    static bool get_key(int key);
    static bool get_key_up(int key);
    static bool get_key_down(int key);

    static float get_mouse_delta_x();
    static float get_mouse_delta_y();
};

#endif