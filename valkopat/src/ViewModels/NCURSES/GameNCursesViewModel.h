#ifndef CERVISEMESTRALKA_GAMENCOURSESVIEWMODEL_H
#define CERVISEMESTRALKA_GAMENCOURSESVIEWMODEL_H
#ifdef USE_NCURSES
#include "../Abstract/GameAbstractViewModel.h"

namespace ViewModel
{
    class GameNCursesViewModel : public GameAbstractViewModel
    {
    public:
        GameNCursesViewModel(const Translate::TranslateEngine* Translation);

        virtual void RenderGame(Game::GameContent* ContentToRender);
    };
}

#endif
#endif //CERVISEMESTRALKA_GAMENCOURSESVIEWMODEL_H
