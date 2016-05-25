#include "GameSDLViewModel.h"
#ifdef USE_SDL

ViewModel::GameSDLViewModel::GameSDLViewModel(const Translate::TranslateEngine* Translation)
        : GameAbstractViewModel(Translation)
{ }

void ViewModel::GameSDLViewModel::RenderGame(Game::GameContent* ContentToRender)
{

}


#endif

