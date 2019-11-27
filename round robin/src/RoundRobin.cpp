#include "RoundRobin.hpp"

RoundRobin::RoundRobin()
{
}

RoundRobin::~RoundRobin()
{
}

void 
RoundRobin::addTask(cTask &newTask)
{
    m_tasks.push_back(newTask);
}

void
RoundRobin::processTasks(uint32_t executionTime)
{
    while (this->m_tasks.size() != 0)
    {

    }
    

}

void 
RoundRobin::executeTaskFor(uint32_t timeForExecution, cTask &task)
{
    for (uint32_t i = 0; i < timeForExecution; i++)
    {
        task.performTask();
    }

}