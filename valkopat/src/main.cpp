#include <iostream>
#include <cstdio>
#include "Exceptions/Exception.h"
#include "Translation/TranslateEngine.h"
#include "ViewModels/ViewModelChooser.h"
#include "Game/NibbleGame.h"


#include <sys/ioctl.h>
int kbhit()
{
    int i;
    ioctl(0, FIONREAD, &i);
    return i; /* return a count of chars available to read */
}

termios SetMode()
{
    struct termios old = {0};
    if (tcgetattr(0, &old) < 0)
        perror("tcsetattr()");
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;
    if (tcsetattr(0, TCSANOW, &old) < 0)
        perror("tcsetattr ICANON");
    return old;
}

void BackMode(termios old)
{
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if (tcsetattr(0, TCSADRAIN, &old) < 0)
        perror("tcsetattr ~ICANON");
}


int main()
{
    char Readed;
    termios old = SetMode();
    while (true)
    {
        int Znaku = kbhit();
        if (Znaku > 0)
        {
            Readed = (char)getchar();
            cout << "Precteno: " << Readed << endl;
            if (Readed == '~')
                break;
        }
    }
    BackMode(old);

    try
    {
        using namespace ViewModel;
        ViewModelChooser* ChoosingOfViewModel = new ViewModelChooser();
        BaseViewModel* RenderEngine = ChoosingOfViewModel->ChooseViewModel();
        delete ChoosingOfViewModel;
        Translate::TranslateEngine* Translation = new Translate::TranslateEngine();
        RenderEngine->init(Translation);

        Game::NibbleGame* game = new Game::NibbleGame(RenderEngine);
        game->init();
        game->run();

        delete game;
        delete RenderEngine;
        delete Translation;

        return 0;
    }
    catch (Exceptions::Exception* e)
    {
        std::cout << e->ToString();
        delete e;
        return 1;
    }
}