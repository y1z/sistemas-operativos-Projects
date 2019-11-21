#include <iostream>
#include "Process.hpp"
#include "ShortestJobFirst.hpp"
#include <random>

// simulates the sjf algorithm
void  sjfAlgorithm(uint32_t ProcessAmount);


int main()
{
    std::cout << "Hello wellcome to the shortest job first algorithm!" << std::endl;
    std::srand(time(nullptr));
    sjfAlgorithm(100);
}

void sjfAlgorithm(uint32_t ProcessAmount)
{
     ShortestJobFirst scheduler;
    for (uint32_t i = 0; i < ProcessAmount; ++i)
    {
        int32_t timeAmount = (std::rand() % 6) + 1;
        scheduler.addProcess(timeAmount);
    }
    scheduler.execute();
}