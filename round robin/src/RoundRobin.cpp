#include "RoundRobin.hpp"
#include <iostream>

RoundRobin::RoundRobin()
{
  m_executingTasks[0] = size_t(-1);
  m_executingTasks[1] = size_t(-1);
}

RoundRobin::~RoundRobin()
{
}

void RoundRobin::addTask(cTask &newTask)
{
  m_tasks.push_back(newTask);
}

void RoundRobin::processTasks(uint32_t executionTime)
{
  size_t totalTasks = m_tasks.size();
  m_removedTasks = 0u;
  while (m_removedTasks < totalTasks)
  {
    //make sure there is more than one task to execute
    if ((totalTasks - m_removedTasks) != 1)
    {
      std::thread lowerHalfProcess(&RoundRobin::processLowerHalfOfTasks, this, executionTime);
      std::thread upperHalfProcess(&RoundRobin::processUpperHalfOfTasks, this, executionTime);

      lowerHalfProcess.join();
      upperHalfProcess.join();
    }
    else
    {

      while ( totalTasks - m_removedTasks == 1)
      {
        this->executeTaskFor(executionTime, m_tasks[0]);

        if (!m_tasks[0].getTimeNeededForTask() > 0)
        {
          this->addTaskIndexForDeletion(0);
          break;
        }
      }

    }

    std::cout << "finished tasks count =" << m_removedTasks << '\n';
    std::this_thread::sleep_for(std::chrono::milliseconds(200));

    this->removeTaskForDeletion();
  }
  printf("\n\n ========<<<[DONE]>>>========");
}

void RoundRobin::processLowerHalfOfTasks(uint32_t executionTime)
{
  //starts at the beginning of the container
  for (size_t i = 0; i < m_tasks.size() / 2; ++i)
  {
    if (m_tasks[i].checkIsBeingUsed() == false)
    {
      this->executeTaskFor(executionTime, m_tasks[i]);
      m_tasks[i].setIsTaskBeingUsed(false);

      if (!m_tasks[i].getTimeNeededForTask() > 0)
      {
        this->addTaskIndexForDeletion(i);
      }
    }
  }
}

void RoundRobin::processUpperHalfOfTasks(uint32_t executionTime)
{
  //starts at the middle of the container
  for (size_t i = m_tasks.size() / 2; i < m_tasks.size() - 1; ++i)
  {
    if (m_tasks[i].checkIsBeingUsed() == false)
    {
      this->executeTaskFor(executionTime, m_tasks[i]);
      m_tasks[i].setIsTaskBeingUsed(false);

      if (!m_tasks[i].getTimeNeededForTask() > 0)
      {
        printf("here is how much time this task needs %u\nTask ID = << %u >>\n===============================\n",
               m_tasks[i].getTimeNeededForTask(),
               m_tasks[i].getId());

        this->addTaskIndexForDeletion(i);
      }
    }
  }
}

void RoundRobin::addTaskIndexForDeletion(size_t index)
{
  std::lock_guard<std::mutex> lock(m_locks[0]);
  m_tasksMarkedForDeletion.emplace_back(index);
}

void RoundRobin::removeTaskForDeletion()
{
  for (size_t index : m_tasksMarkedForDeletion)
  {
    std::cout << "removing task  ID = {" << m_tasks[index].getId() << "}\n";
    m_tasks.erase(m_tasks.begin() + index);
    m_removedTasks++;
  }

  //m_tasks.shrink_to_fit();
  m_tasksMarkedForDeletion.clear();
}

void RoundRobin::executeTaskFor(uint32_t timeForExecution, cTask &task)
{
  for (uint32_t i = 0; i < timeForExecution; i++)
  {
    if (task.getTimeNeededForTask() > 0)
    {
      task.performTask();
      std::this_thread::sleep_for(std::chrono::milliseconds(600));
    }
    else
    {
      break;
    }
  }
}