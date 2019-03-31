#include <chrono>
#include <random>


int getTime();

template<typename T>
T randBetween(int a, int b)
{
    return (T) ((rand() + a) % b);
}
