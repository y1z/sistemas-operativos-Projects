#include "Process.hpp"
#include <algorithm>

static int32_t ProcessIntancesCount = 0;

Process::Process()
{
    m_id = ProcessIntancesCount++;
}

Process::Process(int32_t amount)
    : Process()
{
    m_timeAmount = amount;
}

Process::~Process()
{
}

void Process::setProcessTimeAmount(int32_t amount)
{
    m_timeAmount = amount;
}

int32_t Process::getProcessTimeAmount() const
{
    return m_timeAmount;
}

int32_t Process::getID() const
{
    return m_id;
}

void Process::executeProcess()
{
    --m_timeAmount;
    std::cout << "executing process \n"
              << "time needed to finish [" << m_timeAmount << "]\n";
}

bool Process::operator<(const Process &other) const
{
    return m_timeAmount < other.m_timeAmount;
}

bool Process::operator>(const Process &other) const
{
    return m_timeAmount > other.m_timeAmount;
}
