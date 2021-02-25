#include "WindowManager.h"
int main(){
    WindowManager wm(800, 600, "Engine");
    wm.wait_until_closed();
    return 0;
}