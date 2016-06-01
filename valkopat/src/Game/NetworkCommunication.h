#ifndef CERVISEMESTRALKA_NETWORKCOMMUNICATION_H
#define CERVISEMESTRALKA_NETWORKCOMMUNICATION_H
#include <cstdlib>
#include <string>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <utility>
#include "Enums.h"
#include "../Exceptions/ServerException.h"

using namespace std;
namespace Game
{
    /**
     * Fasace over low network communication
     */
    class NetworkCommunication
    {
    public:
        /**
         * Create listening socket for server
         * @param IPAndPort AP and port of server
         * @param CountOfPlayers Max count of players in game
         * @return Socket of server, -1 otherwise
         */
        static int CreateServerSocket(pair<string, string> IPAndPort, int CountOfPlayers);
        /**
         * Create socket for client
         * @param IPAndPort IP and port to connect
         * @return Socket of client, -1 otherwise
         */
        static int CreateClientSocket(pair<string, string> IPAndPort);

        /**
         * Send hello header
         * @param Socket Socket where send
         */
        static void SendHello(int Socket);
        /**
         * Recive hello header
         * @param Socket Socket where recive
         * @return True if obtained Hello header, false otherwise
         */
        static bool RecvHello(int Socket);

        /**
         * Send informations about map
         * @param Socket Socket where send
         * @param Name Name of map
         * @param Hash Hash of map content
         */
        static void SendMapRequest(int Socket, string Name, size_t Hash);
        /**
         * Recive informations about map
         * @param Socket Socket where recive
         * @param Name Name of level 
         * @param Hash Hash of map content 
         */
        static void RecvMapRequest(int Socket, string& Name, size_t& Hash);

        /**
         * Send answer to map request
         * @param Socket Socket where send
         * @param Have True if is map aviable locally, false otherwise
         */
        static void SendMapRequestAnswer(int Socket, bool Have);
        /**
         * Recive answer to map request
         * @param Socket Socket where recive
         * @param Have True if player have map, false otherwise 
         */
        static void RecvMapRequestAnswer(int Socket, bool& Have);

        /**
         * Send whole map
         * @param Socket Socket where send
         * @param Name Name of level
         * @param Data Data representation of map
         */
        static void SendMapTransfer(int Socket, string Name, string Data);
        /**
         * Recive whole map
         * @param Socket Socket where recive
         * @param Name Name of level 
         * @param Data Data representation of map
         */
        static void RecvMapTransfer(int Socket, string& Name, string& Data);

        /**
         * Send name of player
         * @param Socket Socket where send
         * @param Name Name of palyer
         */
        static void SendName(int Socket, string Name);
        /**
         * Recive name of player
         * @param Socket Socket where recive
         * @param Name Name of player
         */
        static void RecvName(int Socket, string& Name);

        /**
         * Send starting position for player
         * @param Socket Socket where send
         * @param PosX X coordinate of start position
         * @param PosY Y coordinate of start position
         * @param Direction Starting direction of worm
         * @param PlayerID ID of player
         */
        static void SendInitForPlayer(int Socket, int PosX, int PosY, Actions Direction, int PlayerID);
        /**
         * Recive starting position for player
         * @param Socket Socket where recive
         * @param PosX X coordinate of start position
         * @param PosY Y coordinate of start position
         * @param Direction Starting direction of worm
         * @param PlayerID ID of player
         */
        static void RecvInitForPlayer(int Socket, int& PosX, int& PosY, Actions& Direction, int& PlayerID);

        /**
         * Send info that new player was connected
         * @param Socket Socket to send
         * @param NameOfPlayer Name of new player
         * @param PosX X coordinate of new player's starting position
         * @param PosY Y coordinate of new player's starting position
         * @param Direction New player's starting direction
         * @param PlayerID New player's ID
         */
        static void SendPlayerConnected(int Socket, string NameOfPlayer, int PosX, int PosY, Actions Direction,
                                        int PlayerID);
        /**
         * Send start game header
         * @param Socket Socket where send
         */
        static void SendStartGame(int Socket);
        /**
         *
         * @param Socket Socket where recive
         * @param NameOfPlayer Name of connected palyer
         * @param PosX X coordinate of new player's starting position
         * @param PosY Y coordinate of new player's starting position
         * @param Direction Direction of new player's worm
         * @param PlayerID New player's ID
         * @throw Exceptions::ServerException If wrong header recived
         * @return Return true if start game header was recived, otherwise new player was connected
         */
        static bool TryRecvPlayerConnected(int Socket, string& NameOfPlayer, int& PosX, int& PosY, Actions& Direction,
                                           int& PlayerID);

        /**
         * Send action of player
         * @param Socket Socket where send
         * @param Action Action to send
         */
        static void SendPlayerAction(int Socket, Actions Action);
        /**
         * Recive action of player\n
         * Use non-blocking operation, so just proccess all data in buffer
         * @param Socket Socket where recive
         * @param Action Player action
         * @return True if action from user obtained, false otherwise
         */
        static bool TryRecvPlayerAction(int Socket, Actions& Action);

        /**
         * Send what user do
         * @param Socket Socket to send
         * @param IDOfPlayer Id of player, which done action
         * @param Action Action to send
         */
        static void SendActionsOfPlayer(int Socket, int IDOfPlayer, Actions Action);
        /**
         * Send end of wait loop header
         * @param Socket Socket to send
         */
        static void SendEndOfWait(int Socket);
        /**s
         * Recive what other users do
         * @param Socket Socket to recive
         * @param IDOfPlayer ID of user, which done action
         * @param Action Action what user done
         * @return True if action of player recived, false if end of wait loop header recived
         */
        static bool TryRecvActionsOfPlayer(int Socket, int& IDOfPlayer, Actions& Action);
    private:

        /**
         * Send specific header
         * @param Socket Socket to send
         * @param Header Header to send
         */
        static void SendHeader(int Socket, ServerActions Header);
        /**
         * Recive header
         * @param Socket Socket where recive
         * @return Recived header
         */
        static ServerActions RecvHeader(int Socket);
    };
}


#endif //CERVISEMESTRALKA_NETWORKCOMMUNICATION_H
