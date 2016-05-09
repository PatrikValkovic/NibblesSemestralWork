#include "SingpleplayerMenuSDLViewModel.h"
#ifdef USE_SDL

ViewModel::SingpleplayerMenuSDLViewModel::SingpleplayerMenuSDLViewModel(const Translate::TranslateEngine* Translation)
        : SingleplayerMenuAbstractViewModel(Translation)
{ }

std::string ViewModel::SingpleplayerMenuSDLViewModel::NameOfPlayer()
{
    //TODO
    return "";
}

int ViewModel::SingpleplayerMenuSDLViewModel::CountOfAI()
{
    //TODO
    return 0;
}

int ViewModel::SingpleplayerMenuSDLViewModel::Level()
{
    //TODO
    return 0;
}


#endif

