#include <iostream>
#include <chrono>

#include "../include/parallel.hh"

int main()
{
    const int size = 600;
    const int N_REPS = 5;
    const bool openMP = 0;
    parallel x(size, openMP);
    x.DO_LOOP();
}