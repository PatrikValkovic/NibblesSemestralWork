#ifndef CERVISEMESTRALKA_NETMENUABSTRACTVIEWMODEL_H
#define CERVISEMESTRALKA_NETMENUABSTRACTVIEWMODEL_H
#include "ViewModelDerivatingClass.h"

namespace ViewModel
{
    class NetMenuAbstractViewModel : public ViewModelAbstractClass
    {
    public:
        NetMenuAbstractViewModel(const Translate::TranslateEngine* Translate)
                : ViewModelAbstractClass(Translate)
        { }

        virtual ~NetMenuAbstractViewModel()
        { }

        virtual string Level() = 0;
        virtual int CountOfPlayers(int Max) = 0;
        virtual pair<string,string> GetIPAndPort() = 0;
        virtual bool CreateNewServer() = 0;
        virtual void ServerCreated() = 0;
        virtual void ServerNotCreated() = 0;
        virtual void CreatingAndConnectingError() = 0;
        virtual void CannotConnect() = 0;
        virtual void ServerNotRespond() = 0;
        virtual void ServerRespond() = 0;
        virtual void LevelToUse(string NameOfLevel) = 0;
        virtual void HaveMap(bool Have) = 0;
        virtual string GetName() = 0;
        virtual void PlayerConnected(string NameOfPlayer) = 0;
        virtual void BeginGame() = 0;
        virtual void WaitingForRestOfPlayers() = 0;
    };
}
#endif //CERVISEMESTRALKA_NETMENUABSTRACTVIEWMODEL_H
