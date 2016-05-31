#include "DiscardingInput.h"

void Game::Task::DiscardingInput::run()
{
    this->Input->DiscardBuffer();
}

Game::Task::DiscardingInput::DiscardingInput(ViewModel::AbstractInput* Input)
    : Input(Input)
{}



