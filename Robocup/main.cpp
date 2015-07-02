
#include <iostream>
#include <stdlib.h>
#include "Client.h"
#include "Player.h"

#define NAME_INPUT "TreeBots"

int main(int argc, const char * argv[]) {
 
    //First create a client for all the players
    Client *udpClient = Client::createClient(ProtocolTypeUDP, 6000);
    
    Player *goalie = Player::createPlayer(PlayerTypeGoalKeeper, udpClient->connection(), NAME_INPUT);
    goalie->start();
    
    Player *striker1 = Player::createPlayer(PlayerTypeStrikerBottom, udpClient->connection(), NAME_INPUT);
    striker1->start();
    
    Player *striker2 = Player::createPlayer(PlayerTypeStriker, udpClient->connection(), NAME_INPUT);
    striker2->start();
    
    Player *striker3 = Player::createPlayer(PlayerTypeStrikerTop, udpClient->connection(), NAME_INPUT);
    striker3->start();
    
    Player *striker4 = Player::createPlayer(PlayerTypeStrikerCenter, udpClient->connection(), NAME_INPUT);
    striker4->start();
    
    Player *striker5 = Player::createPlayer(PlayerTypeStrikerAux, udpClient->connection(), NAME_INPUT);
    striker5->start();
    
    Player *defender1 = Player::createPlayer(PlayerTypeDefender, udpClient->connection(), NAME_INPUT);
    defender1->start();
    
    Player *defender2 = Player::createPlayer(PlayerTypeDefenderTop, udpClient->connection(), NAME_INPUT);
    defender2->start();
    
    Player *midfield1 = Player::createPlayer(PlayerTypeMidFielder, udpClient->connection(), NAME_INPUT);
    midfield1->start();
    
    Player *midfield2 = Player::createPlayer(PlayerTypeMidFielderTop, udpClient->connection(), NAME_INPUT);
    midfield2->start();
    
    Player *midfield3 = Player::createPlayer(PlayerTypeMidFielderBottom, udpClient->connection(), NAME_INPUT);
    midfield3->start();

    //Waits for the player to finish playing
    goalie->waitCompletion();
    striker1->waitCompletion();
    striker2->waitCompletion();
    striker3->waitCompletion();
    striker4->waitCompletion();
    striker5->waitCompletion();
    defender1->waitCompletion();
    defender2->waitCompletion();
    midfield1->waitCompletion();
    midfield2->waitCompletion();
    midfield3->waitCompletion();

    return 0;
    
}
