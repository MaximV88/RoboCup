/*8921005 303677512 maxim vainshtein*/

#include <iostream>
#include <stdlib.h>
#include "Client.h"
#include "Player.h"

#define NAME_INPUT "TreeBots"

int main(int argc, const char * argv[]) {
    
    //First create a client for all the players
    Client *udpClient = Client::createClient(ProtocolTypeUDP, 6000);
    
 //   Player *goalie = Player::createPlayer(PlayerTypeGoalKeeper, udpClient->connection(), NAME_INPUT);
  //  goalie->start();
    
    Player *striker = Player::createPlayer(PlayerTypeForward, udpClient->connection(), NAME_INPUT);
    striker->start();
    
    
    //Waits for the player to finish playing
  //  goalie->waitCompletion();
    striker->waitCompletion();

    return 0;
    
}
