/*8921005 303677512 maxim vainshtein*/

#include <iostream>
#include <stdlib.h>
#include "Client.h"
#include "Player.h"

#define NAME_INPUT "maxim_va"

int main(int argc, const char * argv[]) {
    
    //First create a client for all the players
    Client *udpClient = Client::createClient(ProtocolTypeUDP, 6000);
    
    Player *testPlayer = Player::createPlayer(PlayerTypeForward, udpClient->connection(), NAME_INPUT);
    testPlayer->start();
    
    //Waits for the player to finish playing
    testPlayer->waitCompletion();
    
    return 0;
    
}
