#include "Utilities.h"
#include <thread>
#include <random>
#include <time.h>

int getTime()
{
    return std::chrono::duration_cast<std::chrono::milliseconds>
        (std::chrono::system_clock::now().time_since_epoch()).count();
}


