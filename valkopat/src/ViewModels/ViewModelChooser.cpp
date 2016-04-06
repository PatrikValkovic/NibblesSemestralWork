#include "ViewModelChooser.h"

ViewModel::BaseViewModel* ViewModel::ViewModelChooser::ChooseViewModel()
{
    using namespace std;
    vector<BaseViewModel*> ViewModels = PrepareViewModels();
    int Choosed = -1;
    do
    {
        for(int a=0;a<(int)ViewModels.size();a++)
            cout << a+1 << " - Use " << ViewModels[a]->GetNameofViewModel() << endl;
        cout << "Your choose: ";
        cin >> Choosed;
        Choosed--;
    } while(Choosed<0 || Choosed>=(int)ViewModels.size());

    for(int a=0;a<(int)ViewModels.size();a++)
        if(a!=Choosed)
            delete ViewModels[a];

    return ViewModels[Choosed];
}

std::vector<ViewModel::BaseViewModel*> ViewModel::ViewModelChooser::PrepareViewModels()
{
    std::vector<BaseViewModel*> ViewModels;
#ifdef USE_CONSOLE
    ViewModels.push_back(new ConsoleViewModel());
#endif
#ifdef USE_SDL
    ViewModels.push_back(new SDLViewModel());
#endif
#ifdef USE_NCURSES
    ViewModels.push_back(new NCursesViewModel());
#endif
    return ViewModels;
}


