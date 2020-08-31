#ifndef PARALLEL_HH
#define PARALLEL_HH

#include <string>
#include <vector>
#include <array>
#include <chrono>
#include <iostream>
#include <cmath>
#include <thread>

#include "omp.h"

class parallel
{
private:
    int n_loops;
    bool openMP = false;
    double duration_ms;

public:
    parallel(int N, bool parallelize);
    ~parallel();

public:
    void DO_LOOP();
    void Procedure(int &rep_id,double &result);
};

#endif // PARALLEL_HH
