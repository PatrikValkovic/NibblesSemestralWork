#include "BaseAITask.h"

Game::Task::BaseAITask::BaseAITask(Worm* WormToControl, Game::GameContent* Game)
    : ControlledWorm(WormToControl), ContentOfGame(Game)
{}

