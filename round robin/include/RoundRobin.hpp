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

public: // constructors
    RoundRobin();
    ~RoundRobin();

public: // functions
    //! adds a task to be processed
    void addTask(cTask &newTask);

    void processTasks(uint32_t executionTime);

private:
    void
    executeTaskFor(uint32_t timeForExecution,cTask &task);

private: // variable
    //! holds all the task
    std::deque<cTask> m_tasks;

    //! determins the maximum amount of task this class can handle
    std::array<std::mutex, 2> m_locks;
};