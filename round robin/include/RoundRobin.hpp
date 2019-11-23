#pragma once
#include "cTask.hpp"

#include <algorithm>
#include <thread>
#include <chrono>
#include <mutex>
#include <deque>
#include <array>
/**
 *@brief will be used to simulate the RoundRobin algorithm  
*/
class RoundRobin
{

public:
    RoundRobin();
    ~RoundRobin();

public:
    void addTask(cTask &newTask);

private:
    //! holds all the task
    std::deque<cTask> m_tasks;

    std::array<std::mutex, 2> m_locks;
};