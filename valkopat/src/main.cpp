#include <iostream>
#include "ViewModels/ViewModelChooser.h"



int main()
{
    using namespace ViewModel;
    ViewModelChooser Chooser;
    BaseViewModel* RenderEngine = Chooser.ChooseViewModel();
    RenderEngine->init();
    RenderEngine->ShowSplashScreen();
    return 0;
}