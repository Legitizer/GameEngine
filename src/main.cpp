#include "./system/window_manager.h"


int main(){
    window_manager wm(800, 600, "Engine");
    wm.wait_until_closed();
    return 0;
}