#ifndef CERVISEMESTRALKA_NETMENUSDLVIEWMODEL_H
#define CERVISEMESTRALKA_NETMENUSDLVIEWMODEL_H
#ifdef USE_SDL
#include "../Abstract/NetMenuAbstractViewModel.h"

namespace ViewModel
{
    class NetMenuSDLViewModel : public NetMenuAbstractViewModel
    {
    public:
        NetMenuSDLViewModel(const Translate::TranslateEngine* Translation);

        virtual string Level();
        virtual int CountOfPlayers(int Max);
        virtual pair<string,string> GetIPAndPort();
        virtual bool CreateNewServer();
        virtual void ServerCreated();
        virtual void ServerNotCreated();
        virtual void CreatingAndConnectingError();
        virtual void CannotConnect();
        virtual void ServerNotRespond();
        virtual void ServerRespond();
        virtual void LevelToUse(string NameOfLevel);
        virtual void HaveMap(bool Have);
        virtual string GetName();
        virtual void PlayerConnected(string NameOfPlayer);
        virtual void BeginGame();
        virtual void WaitingForRestOfPlayers();
    };
}

#endif
#endif //CERVISEMESTRALKA_NETMENUSDLVIEWMODEL_H
