#include "Simulations.h"

void simRandom(int numParticles)
{
    srand(static_cast<unsigned int>(time(nullptr)));
    for (int i = 0; i < numParticles; i++)
    {
        new Particle(randBetween<double>(10, 1590), randBetween<double>(10, 990),
            (randBetween<double>(0, 20) - 10) / 10, (randBetween<double>(0, 20) - 10) / 10, 
            pow(randBetween<double>(1, 10), 3));
    }
}

void sunSystem()
{
    new Particle{800, 500, 0, 0, 5000};
    new Particle{240, 500, 0, 2.3, 10};
    new Particle{950, 500, 0, -6, 5};
    // new Particle{800, 440, -20, 0, 1};
    // new Particle{300, 700, 0.8, 0.4, 1};
    new Particle{1270, 500, 0, -3, 15};
    new Particle{1282, 500, 0, -4, 0.1};
}

void mainLoop(char** argv)
{
    Fl_Window* win = new Fl_Window{1600, 1000};
    if (*argv[1] == 's') {sunSystem();}
    else {simRandom(atof(argv[1]));}
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
}
