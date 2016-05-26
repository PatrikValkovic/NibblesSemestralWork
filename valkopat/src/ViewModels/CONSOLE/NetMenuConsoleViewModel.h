#ifndef CERVISEMESTRALKA_NETMENUCONSOLEVIEWMODEL_H
#define CERVISEMESTRALKA_NETMENUCONSOLEVIEWMODEL_H
#ifdef USE_CONSOLE
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
        virtual pair<string,string> GetServerIPAndPort();
        virtual bool CreateNewServer();
        virtual void ServerCreated();
        virtual void ServerNotCreated();
    };
}

#endif
#endif //CERVISEMESTRALKA_NETMENUCONSOLEVIEWMODEL_H
