#include "cTask.hpp"
#include "RoundRobin.hpp"

#include <iostream>
#include <random>
#include <algorithm>

void Start();

int main()
{
    std::srand(time(nullptr));
    Start();
}

void Start()
{
    RoundRobin roundRobin;
    for(uint32_t i = 0 ; i < 10;++i){
        cTask task;
        task.init((std::rand() % 5) + 1);
        task.setId(i);
       roundRobin.addTask(task);
    }

}
