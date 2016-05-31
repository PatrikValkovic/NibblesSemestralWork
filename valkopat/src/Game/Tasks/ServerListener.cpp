#include "ServerListener.h"

void Game::Task::ServerListener::run()
{
    using namespace Game;

    int IdOfPlayer;
    Actions RecivedAction;
    while(NetworkCommunication::TryRecvActionsOfPlayer(this->CliSocket,IdOfPlayer,RecivedAction))
    {
        if(RecivedAction==Actions::Pause && IdOfPlayer==IdOfCurrentPlayer)
        {
            for_each(this->InGameWorms.begin(),this->InGameWorms.end(),[](Worm* W){
               W->StopPlaying();
            });
        }


        vector<Worm*>::iterator MovingIter = InGameWorms.begin();
        vector<Worm*>::iterator EndIter = InGameWorms.end();
        vector<Worm*>::iterator Finded = find_if(MovingIter,EndIter,[&IdOfPlayer](Worm* W){
            return W->GetId()==IdOfPlayer;
        });

        if(Finded==EndIter)
            throw new Exceptions::ServerException("Obtained wrong ID of worm",,__LINE__,__FILE__);

        Worm* Working = *Finded;
        if(RecivedAction==Actions::Pause)
            Working->StopPlaying();
        else
            Working->SetMoveDirection(RecivedAction);
    }
}

Game::Task::ServerListener::ServerListener(int ClientSocket, vector<Worm*> Worms, int PlayerId)
        : CliSocket(ClientSocket), IdOfCurrentPlayer(PlayerId), InGameWorms(Worms)
{ }



