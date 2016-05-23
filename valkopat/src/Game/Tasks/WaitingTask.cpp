#include <thread>
#include "WaitingTask.h"

const int Game::Task::WaitingTask::WaitingTimeInMiliseconds = 1500;

void Game::Task::WaitingTask::run()
{
    using namespace std::this_thread; // sleep_for, sleep_until
    using namespace std::chrono; // nanoseconds, system_clock, seconds
    time_point<system_clock> BeginOfMethod = system_clock::now();

    sleep_until(BeginOfMethod + milliseconds(WaitingTimeInMiliseconds));
}
