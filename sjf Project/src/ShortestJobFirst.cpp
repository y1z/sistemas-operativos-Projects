#include "ShortestJobFirst.hpp"
#include <algorithm>
#include <thread>
#include <chrono>

ShortestJobFirst::ShortestJobFirst()
{
    m_processes.reserve(100);
}

void ShortestJobFirst::addProcess(const Process &newProcess)
{
    m_processes.emplace_back(newProcess);
}

void ShortestJobFirst::execute()
{
    //organize the processes so the 
    std::sort(m_processes.begin(), m_processes.end());

    for (auto &process : m_processes)
    {
        std::cout << "total amount of time needed to finished process is  <<"<< process.getProcessTimeAmount() << ">> \n\n\n\n\n";

        while (process.getProcessTimeAmount( ) > 0)
        {
            std::cout << "Process Id {"<<process.getID() << "} \n";
            process.executeProcess();
        }
    }
    std::cout << std::endl;
}
