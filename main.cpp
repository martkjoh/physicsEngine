#include "Particles.h" 
#include "Simulations.h"
#include <string>
#include <chrono>


using namespace::std;

int main(int argc, char** argv)
{

    Fl_Window* win = new Fl_Window{1600, 1000}; 
    if (argc == 1 || *argv[1] == 's') {sunSystem();}
    else {simRandom(atof(argv[1]));}
    win->end();
    win->show();
    mainLoop(win);

    return 0;
}