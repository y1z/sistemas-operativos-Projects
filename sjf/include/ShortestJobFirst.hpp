#pragma once
#include "Process.hpp"

#include <vector>

/**
 * @brief this class simulates the algorithm 'sjf' or ShortestJobFirst
*/

class ShortestJobFirst
{
public:
    ShortestJobFirst();
    ~ShortestJobFirst() = default;


    //! adds a process to the algorithm 
    void
    addProcess(const Process &newProcess);

    void 
    execute();
private:
    //! container for processes
    std::vector<Process> m_processes;
};