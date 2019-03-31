#include <FL/Fl_Window.H>
#include <Fl/Fl_Box.H>
#include "Particles.h"
#include "Utilities.h"
#include <chrono>
#include <thread>
#include <vector>


using namespace::std;

int main()
{
    Fl_Window* win = new Fl_Window{1600, 1000};
    new Particle(400, 200, 0.3, 0.2);
    new Particle(1200, 200, -0.1, 0.2);
    new Particle(800, 600, 0, 0);
    win->end();
    win->show();

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

    return 0;
}