#pragma once
#include "cTask.hpp"

#include <algorithm>
#include <thread>
#include <chrono>
#include <mutex>
#include <deque>
#include <array>
#include <atomic>
/**
 *@brief will be used to simulate the RoundRobin algorithm  
*/
class RoundRobin
{

public: // constructors
  RoundRobin();
  ~RoundRobin();

public: // functions
  //! adds a task to be processed
  void addTask(cTask &newTask);

  void processTasks(uint32_t executionTime);

  //!@brief executes only one half of the tasks(this is done so it become possible to use multiple thread in paralle)
  void processLowerHalfOfTasks(uint32_t executionTime);

  //!@brief executes only one half of the tasks(this is done so it become possible to use multiple thread in paralle)
  void processUpperHalfOfTasks(uint32_t executionTime);

private:
//!@brief add the index of the process that is going to be deleted
  void
  addTaskIndexForDeletion(size_t index);

  void 
  removeTaskForDeletion();

  void
  executeTaskFor(uint32_t timeForExecution, cTask &task);

private: // variable
  //! holds all the task
  std::deque<cTask> m_tasks;

  std::vector<size_t> m_tasksMarkedForDeletion;

  //! determins the maximum amount of task this class can handle
  std::array<std::mutex, 2> m_locks;

  //! keeps track of which task are being executed
  std::array<std::atomic<size_t>, 2> m_executingTasks;

  size_t m_removedTasks{0};
};