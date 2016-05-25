#include "GameNCursesViewModel.h"
#ifdef USE_NCURSES

ViewModel::GameNCursesViewModel::GameNCursesViewModel(const Translate::TranslateEngine* Translation)
        : GameAbstractViewModel(Translation)
{ }

void ViewModel::GameNCursesViewModel::RenderGame(Game::GameContent* ContentToRender)
{

}

#endif



