#include "GameConsoleViewModel.h"
#ifdef USE_CONSOLE

ViewModel::GameConsoleViewModel::GameConsoleViewModel(const Translate::TranslateEngine* Translate)
        : GameAbstractViewModel(Translate)
{ }


void ViewModel::GameConsoleViewModel::RenderGame(Game::GameContent* ContentToRender)
{
    using namespace std;
    using Game::Worm;
    using Game::Point;

    //prepare map
    char** Canvas = new char*[ContentToRender->Ground->GetHeight()];
    for(int a=0;a<ContentToRender->Ground->GetHeight();a++)
        Canvas[a] = new char[ContentToRender->Ground->GetWidth()];

    for (int a = 0; a < ContentToRender->Ground->GetHeight(); a++)
        for (int b = 0; b < ContentToRender->Ground->GetWidth(); b++)
            Canvas[a][b] = ' ';

    //prepare walls
    vector<Point> Walls = ContentToRender->Ground->GetWalls();
    vector<Point>::iterator Moving = Walls.begin();
    vector<Point>::iterator End = Walls.end();
    for (; Moving != End; Moving++)
        Canvas[Moving->GetPositionY()][Moving->GetPositionX()] = '#';

    //TODO DEBUG
    cout << "GrubPos: " << ContentToRender->GetFood().GetPositionY() << ':'
         << ContentToRender->GetFood().GetPositionX() << endl;
    //prepare grub
    Canvas[ContentToRender->GetFood().GetPositionY()][ContentToRender->GetFood().GetPositionX()] = '$';

    //prepare worms
    vector<Worm*> WormsToRender(ContentToRender->Worms.begin(),ContentToRender->Worms.end());
    WormsToRender.push_back(ContentToRender->Player);
    vector<Worm*>::iterator MovingWorm = WormsToRender.begin();
    vector<Worm*>::iterator EndWorms = WormsToRender.end();
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
    for (int a = 0; a <= ContentToRender->Ground->GetWidth() + 1; a++)
        cout << '-';
    cout << endl;
    for (int r = 0; r < ContentToRender->Ground->GetHeight(); r++)
    {
        cout << '|';
        for (int c = 0; c < ContentToRender->Ground->GetWidth(); c++)
            cout << Canvas[r][c];
        cout << '|';
        cout << endl;
    }
    for (int a = 0; a <= ContentToRender->Ground->GetWidth() + 1; a++)
        cout << '-';
    cout << endl;

    //delete map
    for(int a=0;a<ContentToRender->Ground->GetHeight();a++)
        delete [] Canvas[a];
    delete [] Canvas;


    //render score
    MovingWorm = WormsToRender.begin();
    EndWorms = WormsToRender.end();
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



