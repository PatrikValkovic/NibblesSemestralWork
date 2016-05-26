#ifndef CERVISEMESTRALKA_SINGPLEPLAYERMENUNCURSESVIEWMODEL_H
#define CERVISEMESTRALKA_SINGPLEPLAYERMENUNCURSESVIEWMODEL_H
#ifdef USE_NCURSES
#include "../Abstract/SingleplayerMenuAbstractViewModel.h"
namespace ViewModel
{
    class SingleplayerMenuNCursesViewModel : public SingleplayerMenuAbstractViewModel
    {
    public:
        SingleplayerMenuNCursesViewModel(const Translate::TranslateEngine* Translation);

        virtual std::string NameOfPlayer();
        virtual int CountOfAI(int Max);
        virtual string Level() ;
        virtual string LevelOfAI(std::vector<string> MenuEntries);
    };
}
#endif
#endif //CERVISEMESTRALKA_SINGPLEPLAYERMENUNCURSESVIEWMODEL_H
