#include "./system/window_manager.h"


int main(){
    window_manager wm(1920, 1080, "Engine");
    wm.wait_until_closed();
    return 0;
}