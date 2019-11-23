#include "cTask.hpp"
// std  includes
#include <iostream>

cTask::cTask()
{
    is_beingUsed.store(false);
}

cTask::cTask(const cTask &other){
m_id = other.m_id;
m_timeNeededToFinish = other.m_timeNeededToFinish;
this->is_beingUsed.store(other.is_beingUsed.load());
}

cTask::~cTask()
{
}

uint32_t cTask::getTimeNeededForTask() const
{
    return m_timeNeededToFinish;
}

uint32_t cTask::getId() const
{
    return m_id;
}

void cTask::setId(uint32_t id)
{
    m_id = id;
}

void cTask::setIsTaskBeingUsed(bool beingUsed){
    this->is_beingUsed.store(beingUsed);
}

void cTask::init(uint32_t timeForTask)
{
    m_timeNeededToFinish = timeForTask;
}

void cTask::performTask()
{
    --m_timeNeededToFinish;
    is_beingUsed = true;
    std::cout << "time needed to finish [" << m_timeNeededToFinish << "]\n";
}

bool cTask::checkIsBeingUsed() const
{
    return this->is_beingUsed.load();
}