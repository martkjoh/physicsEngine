#include "Particles.h"
#include <chrono>


using namespace::std;

int main(int argc, char** argv)
{
    cout << argv[0] << endl;
    cout << argv[1] << endl;
    startSimulation(atof(argv[1]));

    return 0;
}