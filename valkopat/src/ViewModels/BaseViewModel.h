#ifndef CERVISEMESTRALKA_BASEVIEWMODEL_H
#define CERVISEMESTRALKA_BASEVIEWMODEL_H
#include <vector>
#include <cstring>

namespace ViewModel
{
    class SplashScreenAbstractViewModel
    {
    public:
        virtual ~SplashScreenViewModel()
        { }

        virtual void ShowSplashScreen() = 0;
    };

    class MenuAbstractViewModel
    {
    public:
        struct MenuEntry
        {
            int index;
            std::string Text;
        };

        virtual ~MenuAbstractViewModel()
        { }

        virtual int ShowMenu(std::vector<MenuEntry>) = 0;
    };

    class LanguageAbstractViewModel
    {
    public:
        struct LanguageEntry
        {
            int Index;
            std::string Shortcut;
            std::string NameOfLanguage;
        };

        virtual ~LanguageAbstractViewModel()
        { }

        virtual int ShowMenu(std::vector<LanguageEntry>) = 0;
    };

    class MultiplayerMenuAbstractViewModel
    {
    public:
        virtual ~MultiplayerMenuAbstractViewModel()
        { }
    };

    class NetMenuAbstractViewModel
    {
    public:
        virtual ~NetMenuAbstractViewModel()
        { }
    };

    class SingleplayerMenuAbstractViewModel
    {
    public:
        virtual ~SingleplayerMenuAbstractViewModel()
        { }
    };

    class GameAbstractViewModel
    {
    public:
        virtual ~GameAbstractViewModel()
        { }
    };

    class ScoreAbstractViewModel
    {
    public:
        virtual ~ScoreAbstractViewModel()
        { }
    };

    class BaseViewModel
    {
    public:
        virtual ~BaseViewModel()
        { }

        virtual const char* GetNameofViewModel() = 0;
        virtual void init() = 0;

        virtual SplashScreenAbstractViewModel* SplashScreenModel() = 0;
        virtual MenuAbstractViewModel* MenuModel() = 0;
        virtual LanguageAbstractViewModel* LanguageModel() = 0;
        virtual MultiplayerMenuAbstractViewModel* MultiplayerModel() = 0;
        virtual NetMenuAbstractViewModel* NetModel() = 0;
        virtual SingleplayerMenuAbstractViewModel* SingleplayerModel() = 0;
        virtual GameAbstractViewModel* GameModel() = 0;
        virtual ScoreAbstractViewModel* ScoreModel() = 0;
    };
}

#endif //CERVISEMESTRALKA_BASEVIEWMODEL_H
