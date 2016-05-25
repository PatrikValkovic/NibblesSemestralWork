#include "SplashScreenGameState.h"

GameStates::AbstractGameState* GameStates::SplashScreenGameState::run()
{
    using namespace std::this_thread; // sleep_for, sleep_until
    using namespace std::chrono; // nanoseconds, system_clock, seconds
    time_point<system_clock> BeginOfMethod = system_clock::now();

    this->RenderingModel->SplashPauseScreenModel()->ShowSplashScreen();

    sleep_until(BeginOfMethod + seconds(this->SleepForSecond));
    return NextState;
}

GameStates::SplashScreenGameState::SplashScreenGameState(ViewModel::BaseViewModel* RenderingModel)
        : AbstractGameState(RenderingModel), SleepForSecond(0) //TODO replace by 1
{ }

void GameStates::SplashScreenGameState::AddStates(MenuGameState* NextState)
{
    this->NextState = NextState;
}







