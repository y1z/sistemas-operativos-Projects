#include "cTask.hpp"
#include "RoundRobin.hpp"

#include <iostream>
#include <random>
#include <algorithm>

void Start();

void simulateRoundRobin(const uint32_t taskNum);

int main()
{
    std::srand(time(nullptr));
    Start();
}

void Start()
{
    uint32_t userTaskAmount{0};
    std::cout << "please input the amount of task you what to execute \n->";
    std::cin >> userTaskAmount;
    std::cout << "Start ";
    simulateRoundRobin(userTaskAmount);
}

void simulateRoundRobin(const uint32_t taskNum)
{
    RoundRobin scheduler;
   for (uint32_t i = 0; i < taskNum; i++)
   {
       cTask ramdomTask;
       ramdomTask.init((std::rand() % 5) + 1,i);
       scheduler.addTask(ramdomTask);
   }
    
    
}
