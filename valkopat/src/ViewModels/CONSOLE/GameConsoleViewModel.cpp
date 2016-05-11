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
    char Canvas[Playground->GetHeight()][Playground->GetWidth()];

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
        vector<Game::Worm::Segment> Segments = RenderingWorm->GetSegment();
        for (int a = 0; a < (int) Segments.size(); a++)
        {
            if (a == 0)
                Canvas[Segments[a].GetPositionY()][Segments[a].GetPositionX()] = '@';
            else
                Canvas[Segments[a].GetPositionY()][Segments[a].GetPositionX()] = '+';
        }

    }

    //render it
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

    //render score
    MovingWorm = Worms.begin();
    EndWorms = Worms.end();
    for(;MovingWorm!=EndWorms;MovingWorm++)
        cout << Translation->GetTranslation("ScoreOf") << ' ' << (*MovingWorm)->GetName() << ": " << (*MovingWorm)->GetSegment().size() << endl;
}


#endif



