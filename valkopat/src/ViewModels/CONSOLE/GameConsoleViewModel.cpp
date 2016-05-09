#include "GameConsoleViewModel.h"
#ifdef USE_CONSOLE

ViewModel::GameConsoleViewModel::GameConsoleViewModel(const Translate::TranslateEngine* Translate)
        : GameAbstractViewModel(Translate)
{ }


void ViewModel::GameConsoleViewModel::RenderGame(Game::PlayGround* Playground, std::vector<Game::Worm*> Worms)
{
    using namespace std;
    char Canvas[Playground->GetHeight()][Playground->GetWidth()];

    for(int a=0;a<Playground->GetHeight();a++)
        for(int b=0;b<Playground->GetWidth();b++)
            Canvas[a][b] = ' ';

    //prepare it
    vector<Game::Point> Walls = Playground->GetWalls();
    vector<Game::Point>::iterator Moving = Walls.begin();
    vector<Game::Point>::iterator End = Walls.end();
    for(;Moving!=End;Moving++)
        Canvas[Moving->GetPositionY()][Moving->GetPositionX()] = '#';

    //render it
    for(int r=0;r<Playground->GetHeight();r++)
    {
        for (int c = 0; c < Playground->GetWidth(); c++)
            cout << Canvas[r][c];
        cout << endl;
    }

    delete Playground;
    for_each(Worms.begin(),Worms.end(),[](Game::Worm* X) { delete X; });
}


#endif



