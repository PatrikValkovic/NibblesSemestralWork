#include "PlayingState.h"

GameStates::AbstractGameState* GameStates::PlayingState::run()
{
    ViewModel::GameConsoleViewModel* Rendering = (ViewModel::GameConsoleViewModel*)this->RenderingModel->GameModel();


    while(true)
    {
        vector<Worm*> WormsToRender(this->ContentOfGame->Worms.begin(),this->ContentOfGame->Worms.end());
        WormsToRender.push_back(this->ContentOfGame->Player);

        this->ValidatePositionsOfWorms();

        Rendering->RenderGame(this->ContentOfGame->Ground,WormsToRender);

        cout << "Update" << endl;
        cin.get();

        this->ContentOfGame->Player->Move(Game::Directions::Up);
    }
}

GameStates::PlayingState::PlayingState(ViewModel::BaseViewModel* RenderingModel)
        : AbstractGameState(RenderingModel)
{ }

void GameStates::PlayingState::AddStates(MenuGameState* MenuState, GamePauseState* PauseState)
{
    this->Menu = MenuState;
    this->Pause = PauseState;
}

void GameStates::PlayingState::ClearContent(Game::GameContent* NewContent)
{
    delete ContentOfGame;
    ContentOfGame = NewContent;
}

GameStates::PlayingState::~PlayingState()
{
    delete ContentOfGame;
}

void GameStates::PlayingState::ValidatePositionsOfWorms()
{
    vector<Worm*> WormsToRender(this->ContentOfGame->Worms.begin(),this->ContentOfGame->Worms.end());
    WormsToRender.push_back(this->ContentOfGame->Player);

    vector<Worm*>::iterator Moving = WormsToRender.begin();
    vector<Worm*>::iterator End = WormsToRender.end();
    for(;Moving!=End;Moving++)
        (*Moving)->ValidatePosition(this->ContentOfGame->Ground->GetWidth(),
                                    this->ContentOfGame->Ground->GetHeight());
}











