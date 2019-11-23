#include <iostream>
#include "Process.hpp"
#include "ShortestJobFirst.hpp"
#include <random>

// simulates the sjf algorithm
void sjfAlgorithm(uint32_t ProcessAmount);

void start();

int main()
{
    start();
}

void start()
{
    std::cout << "Hello wellcome to the shortest job first algorithm!\n" << std::endl;
    std::srand(time(nullptr));

    uint32_t options{0  };
    std::cout << "please select the number of processes to be simulated\n->";
    std::cin >> options;
    sjfAlgorithm(options);

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