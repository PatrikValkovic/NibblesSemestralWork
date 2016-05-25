#ifndef CERVISEMESTRALKA_SINGPLEPLAYERABSTRACTVIEWMODEL_H
#define CERVISEMESTRALKA_SINGPLEPLAYERABSTRACTVIEWMODEL_H
#include <string>
#include <map>
#include "ViewModelDerivatingClass.h"


namespace ViewModel
{
    class SingleplayerMenuAbstractViewModel : public ViewModelAbstractClass
    {
    protected:
        std::string Name;
        int CountOfAIInGame;
        int LevelIndex;
    public:
        SingleplayerMenuAbstractViewModel(const Translate::TranslateEngine* Translate)
                : ViewModelAbstractClass(Translate)
        { }

        virtual ~SingleplayerMenuAbstractViewModel()
        { }

        virtual std::string NameOfPlayer() = 0;
        virtual int CountOfAI(int Max) = 0;

        virtual string Level() = 0;
        virtual int LevelOfAI(std::map<int, string> MenuEntries) = 0;


    };
}

#endif //CERVISEMESTRALKA_SINGPLEPLAYERABSTRACTVIEWMODEL_H
