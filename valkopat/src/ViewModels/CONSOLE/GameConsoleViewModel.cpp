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

    vector<Game::Worm*>::iterator MovingWorm = Worms.begin();
    vector<Game::Worm*>::iterator EndWorms = Worms.end();
    for(;MovingWorm!=EndWorms;MovingWorm++)
    {
        Game::Worm* RenderingWorm = *MovingWorm;
        vector<Game::Worm::Segment> Segments = RenderingWorm->GetSegment();
        for(int a=0;a<(int)Segments.size();a++)
            Canvas[Segments[a].GetPositionY()][Segments[a].GetPositionX()] = '+';
    }

    //render it
    for(int a=0;a<=Playground->GetWidth()+1;a++)
        cout << '-';
    cout << endl;
    for(int r=0;r<Playground->GetHeight();r++)
    {
        cout << '|';
        for (int c = 0; c < Playground->GetWidth(); c++)
            cout << Canvas[r][c];
        cout << '|';
        cout << endl;
    }
    for(int a=0;a<=Playground->GetWidth()+1;a++)
        cout << '-';
    cout << endl;
}


#endif



