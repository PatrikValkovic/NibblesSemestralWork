#ifndef CERVISEMESTRALKA_NETMENUNCURSESVIEWMODEL_H
#define CERVISEMESTRALKA_NETMENUNCURSESVIEWMODEL_H
#ifdef USE_NCURSES
#include "../Abstract/NetMenuAbstractViewModel.h"

namespace ViewModel
{
    class NetMenuNCursesVIewModel : public NetMenuAbstractViewModel
    {
    public:
        NetMenuNCursesVIewModel(const Translate::TranslateEngine* Translation);

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
#endif //CERVISEMESTRALKA_NETMENUNCURSESVIEWMODEL_H
