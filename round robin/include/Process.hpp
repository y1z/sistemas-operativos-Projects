#pragma once
#include <cstdint>
#include <iostream>
#include <time.h>

/**
 * @brief this class will be used to simulate a process  
*/
class Process
{
public: // constructors
    Process();
    Process(int32_t amount);
    ~Process();

public: // functions
    // will control how mach time a process
    void
    setProcessTimeAmount(int32_t amount);

    //! tells me how long a process is going to take
    int32_t
    getProcessTimeAmount() const;

//! @return a identifier  
    int32_t
    getID() const;

    void
    executeProcess();

public: // operators
    bool operator<(const Process &other) const;
    bool operator>(const Process &other) const;

private:
    /** will be used know how much a process needs to execute*/
    int32_t m_timeAmount{-1};
    int32_t m_id{0};
};