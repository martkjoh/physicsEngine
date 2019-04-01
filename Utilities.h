#include <chrono>
#include <random>
#include <time.h>
#include <thread>


int getTime();

template<typename T>
T randBetween(int a, int b)
{
    return (T) ((rand() + a) % b);
}
