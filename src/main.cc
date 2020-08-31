#include <iostream>
#include <chrono>

#include "../include/parallel.hh"

int main()
{
    const int size = 600;
    const int N_REPS = 5;
    
    //?Turn openMP multi-threaded application ON or OFF
    const bool openMP = 1;
    
    parallel x(size, openMP);
    x.DO_LOOP();
}