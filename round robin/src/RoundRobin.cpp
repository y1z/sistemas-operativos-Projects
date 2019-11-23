#include "RoundRobin.hpp"

RoundRobin::RoundRobin()
{
}

RoundRobin::~RoundRobin()
{
}

void RoundRobin::addTask(cTask &newTask)
{
    m_tasks.push_back(newTask);
}