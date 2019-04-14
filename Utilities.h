#pragma once

#include <chrono>
#include <random>
#include <time.h>
#include <thread>
#include "Simulations.h"

int getTime();

void mainLoop(Fl_Window* win);

template<typename T>
T randBetween(int a, int b)
{
    return (T) ((rand() + a) % b);
}