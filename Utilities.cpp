#include "Utilities.h"


int getTime()
{
    return std::chrono::duration_cast<std::chrono::milliseconds>
        (std::chrono::system_clock::now().time_since_epoch()).count();
}


void mainLoop(Fl_Window* win)
{
    auto time = chrono::steady_clock::now();
    while(win->shown())
    {
        updateState();
        Fl::check();
        Fl::redraw();
        win->redraw();
        this_thread::sleep_until(time);
        time += chrono::microseconds((int) 1000000 / 60);
    }
}
