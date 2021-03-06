#ifndef CERVISEMESTRALKA_NETMENUCONSOLEVIEWMODEL_H
#define CERVISEMESTRALKA_NETMENUCONSOLEVIEWMODEL_H
#ifdef USE_CONSOLE
#include <climits>
#include <map>
#include <iostream>
#include <algorithm>
#include "../Abstract/NetMenuAbstractViewModel.h"
#include "../../Game/PlaygroundFactory.h"

using namespace std;
namespace ViewModel
{
    class NetMenuConsoleViewModel : public NetMenuAbstractViewModel
    {
    public:
        NetMenuConsoleViewModel(const Translate::TranslateEngine* Translate);

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
#endif //CERVISEMESTRALKA_NETMENUCONSOLEVIEWMODEL_H
