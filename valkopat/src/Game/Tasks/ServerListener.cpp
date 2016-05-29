#include "ServerListener.h"

void Game::Task::ServerListener::run()
{
    ServerActions Recived;
    while(true)
    {
        recv(CliSocket,&Recived,sizeof(ServerActions),0);
        if(Recived == ServerActions::Wait)
            return;

        if(Recived != ServerActions::ActionsSend)
            throw "Fuck"; //TODO

        int PlayerIndex;
        Actions RecivedAction;
        recv(CliSocket,&PlayerIndex,sizeof(int),0);
        recv(CliSocket,&RecivedAction,sizeof(Actions),0);

        vector<Worm*>::iterator MovingIter = InGameWorms.begin();
        vector<Worm*>::iterator EndIter = InGameWorms.end();
        vector<Worm*>::iterator Finded = find_if(MovingIter,EndIter,[&PlayerIndex](Worm* W){
            return W->GetId()==PlayerIndex;
        });

        if(Finded==EndIter)
            continue;

        Worm* Working = *Finded;
        if(RecivedAction==Actions::Pause)
            Working->StopPlaying();
        else
            Working->SetMoveDirection(RecivedAction);
    }
}

Game::Task::ServerListener::ServerListener(int ClientSocket, vector<Worm*> Worms)
        : CliSocket(ClientSocket), InGameWorms(Worms)
{ }



