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
    new Particle{800, 500, 0, 0, 1500};
    new Particle{240, 500, 0, 4, 10};
    new Particle{1200, 500, 0, -5, 10};
}
