#include "cTask.hpp"
// std  includes
#include <iostream>

cTask::cTask()
{
    is_beingUsed.store(false);
}

cTask::cTask(const cTask &other)
{
    m_id = other.m_id;
    this->m_timeNeededToFinish.store( other.m_timeNeededToFinish.load());
    this->is_beingUsed.store(other.is_beingUsed.load());

std::cout << "Copy of task is ocurring ID = [" << m_id << "]\n";
    /*std::cout << "Task is finish and remove from queue ID =[" << m_id << "]\n"
              << "time needed to finish task is TIME TO FINISH TASK[" << m_timeNeededToFinish << "]\n";*/
}

cTask::~cTask()
{
}

uint32_t cTask::getTimeNeededForTask() const
{
    return m_timeNeededToFinish.load();
}

size_t cTask::getId() const
{
    return this->m_id;
}

void cTask::setId(uint32_t id)
{
    m_id = id;
}

void cTask::setIsTaskBeingUsed(bool beingUsed)
{
    this->is_beingUsed.store(beingUsed);
}

void cTask::init(uint32_t timeForTask, uint32_t IdForTask)
{
    m_timeNeededToFinish.store (timeForTask);
    m_id = IdForTask;
}

void cTask::performTask()
{
    --m_timeNeededToFinish;
    is_beingUsed.store(true);
    std::cout << "time needed to finish [" << m_timeNeededToFinish << "]\n";
    std::cout << "Task ID = {{" << m_id << "}} \n\n" <<std::endl;
}

bool cTask::checkIsBeingUsed() const
{
    return this->is_beingUsed.load();
}

cTask &cTask::operator=(const cTask &other)
{
    m_id = other.m_id;
    this->m_timeNeededToFinish.store( other.m_timeNeededToFinish.load());
    this->is_beingUsed.store(other.is_beingUsed.load());

    return *this;
}