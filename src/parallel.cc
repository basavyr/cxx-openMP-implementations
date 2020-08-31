#include "../include/parallel.hh"

parallel::parallel(int N, bool parallelize)
{
    n_loops = N;
    openMP = parallelize;
}

parallel::~parallel()
{
    std::cout << "Process ended successfully...";
    std::cout << "\n";
    if (openMP)
    {
        std::cout << "Parallelization: ON..."
                  << "\n";
    }
    else
    {
        std::cout << "Parallelization: OFF..."
                  << "\n";
    }
    std::cout << "Duration: " << duration_ms << " s";
    std::cout << "\n";
}

void parallel::Procedure(int &rep_id)
{
    double count = 0.0;
    for (auto i1 = 0; i1 < n_loops; ++i1)
    {
        for (auto i2 = 0; i2 < n_loops; ++i2)
        {
            for (auto i3 = 0; i3 < n_loops; ++i3)
            {
                count += 0.1;
            }
        }
    }
    std::cout << "rep-" << rep_id << " ";
    // std::cout << sqrt(count) * rep_id;
    std::cout << "\n";
}

void parallel::DO_LOOP()
{
    auto start = std::chrono::system_clock::now();
    if (openMP)
#pragma omp parallel for
    {
        for (auto gamma_id = 15; gamma_id <= 25; ++gamma_id)
        {
            Procedure(gamma_id);
        }
    }
    else
    {
        for (auto gamma_id = 15; gamma_id <= 25; ++gamma_id)
        {
            Procedure(gamma_id);
        }
    }
    duration_ms = static_cast<double>(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - start).count() / 1000.0);
}