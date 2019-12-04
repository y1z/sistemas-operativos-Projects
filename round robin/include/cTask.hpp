#pragma once
#include <cstdint>
#include <cstddef>
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

public: //functions
    //!@returns m_timeNeededToFinish
    uint32_t getTimeNeededForTask() const;

    size_t getId() const;

    void setId(uint32_t id);

    void setIsTaskBeingUsed(bool beingUsed);
    //! indicates how long a task is going to take
    void init(uint32_t timeForTask, uint32_t idForTask);

    //!\brief simulates performing a task
    void performTask();

    //!@brief this is to know if another thread is already executing this Task
    bool checkIsBeingUsed() const;

public: //operators

cTask &operator =(const  cTask &other);
private:
    size_t m_id;

    //! how much time this task needs to finish
   std::atomic< uint32_t> m_timeNeededToFinish{3};

    //! check if its already being used by something else
    std::atomic_bool is_beingUsed;
};