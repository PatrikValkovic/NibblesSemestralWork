#include "Single.h"

bool Game::Event::Single::HasActions()
{
    return true;
}

bool Game::Event::Single::ProccessActions()
{
    Keys Key;
    bool Continue = true;
    int PlayerI;
    Actions Act;

    this->InputClass->StartAgain();

    while ((Key = InputClass->GetNextStroke()) != Keys::NONE)
        if(this->ActualSetting->GetAction(Key,PlayerI,Act))
        {
            if (Act == Actions::Pause)
                Continue = false;

            if(PlayerI==this->PlayerIndex)
                this->Player->SetMoveDirection(Act);
        }

    return Continue;
}

Game::Event::Single::Single(Worm* Player,
                            ViewModel::AbstractInput* InputMethod,
                            int IndexOfPlayer,
                            Settings* Set)
        : Player(Player),
          PlayerIndex(IndexOfPlayer),
          InputClass(InputMethod),
          ActualSetting(Set)
{ }











