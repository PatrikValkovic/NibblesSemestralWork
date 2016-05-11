#include "GameConsoleViewModel.h"
#ifdef USE_CONSOLE

ViewModel::GameConsoleViewModel::GameConsoleViewModel(const Translate::TranslateEngine* Translate)
        : GameAbstractViewModel(Translate)
{ }


void ViewModel::GameConsoleViewModel::RenderGame(Game::PlayGround* Playground, std::vector<Game::Worm*> Worms)
{
    using namespace std;
    using Game::Worm;
    using Game::Point;

    //prepare map
    char** Canvas = new char*[Playground->GetHeight()];
    for(int a=0;a<Playground->GetHeight();a++)
        Canvas[a] = new char[Playground->GetWidth()];

    for (int a = 0; a < Playground->GetHeight(); a++)
        for (int b = 0; b < Playground->GetWidth(); b++)
            Canvas[a][b] = ' ';

    //prepare walls
    vector<Point> Walls = Playground->GetWalls();
    vector<Point>::iterator Moving = Walls.begin();
    vector<Point>::iterator End = Walls.end();
    for (; Moving != End; Moving++)
        Canvas[Moving->GetPositionY()][Moving->GetPositionX()] = '#';

    //prepare worms
    vector<Worm*>::iterator MovingWorm = Worms.begin();
    vector<Worm*>::iterator EndWorms = Worms.end();
    for (; MovingWorm != EndWorms; MovingWorm++)
    {
        Game::Worm* RenderingWorm = *MovingWorm;
        if(!RenderingWorm->IsPlaying())
            continue;

        vector<Game::Worm::Segment> Segments = RenderingWorm->GetSegment();
        for (int a = (int)Segments.size()-1; a >= 0; a--)
        {
            if (a == 0)
                Canvas[Segments[a].GetPositionY()][Segments[a].GetPositionX()] = '@';
            else
                Canvas[Segments[a].GetPositionY()][Segments[a].GetPositionX()] = '+';
        }

    }

    //render it
    cout << endl;
    for (int a = 0; a <= Playground->GetWidth() + 1; a++)
        cout << '-';
    cout << endl;
    for (int r = 0; r < Playground->GetHeight(); r++)
    {
        cout << '|';
        for (int c = 0; c < Playground->GetWidth(); c++)
            cout << Canvas[r][c];
        cout << '|';
        cout << endl;
    }
    for (int a = 0; a <= Playground->GetWidth() + 1; a++)
        cout << '-';
    cout << endl;

    //delete map
    for(int a=0;a<Playground->GetHeight();a++)
        delete [] Canvas[a];
    delete [] Canvas;


    //render score
    MovingWorm = Worms.begin();
    EndWorms = Worms.end();
    for(;MovingWorm!=EndWorms;MovingWorm++)
    {
        cout << Translation->GetTranslation("ScoreOf") << ' ' << (*MovingWorm)->GetName() << ": " <<
        (*MovingWorm)->GetSegment().size();
        if (!(*MovingWorm)->IsPlaying())
            cout << "\t" << Translation->GetTranslation("WormDead");
        cout << endl;
    }
}


#endif



