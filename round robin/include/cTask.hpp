#pragma once
#include <cstdint>
#include <atomic>

/**
 * @brief wil be used to represent a task on your computer for the round-robin
 * algorithm
*/
class cTask
{
public:
    cTask();
    cTask(const cTask &other);
    ~cTask();

public:
    //!@returns m_timeNeededToFinish
    uint32_t getTimeNeededForTask() const;

    uint32_t getId() const;

    void setId(uint32_t id);

    void setIsTaskBeingUsed(bool beingUsed);
    //! indicates how long a task is going to take
    void init(uint32_t timeForTask,uint32_t idForTask);

    //!\brief simulates performing a task
    void performTask();

    bool checkIsBeingUsed() const;



private:
    //! how much time this task needs to finish
    uint32_t m_timeNeededToFinish{3};

    uint32_t m_id;

    //! check if its already being used by something else
    std::atomic_bool is_beingUsed;
};