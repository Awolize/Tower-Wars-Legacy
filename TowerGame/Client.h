#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <vector>
#include "StoreMenu.h"
#include "Player.h"
#include "Ground.h"

class Client
{
public:
    Client(sf::RenderWindow &window, sf::TcpSocket &socket) 
	: window(window), socket(socket) {};

    void RunClient();
private:
    void userInterface();
    void Update();
    void Draw();

    sf::RenderWindow &window;
    sf::TcpSocket &socket;
    float deltaTime = 0.0f;
    sf::Clock clock;
    bool ifNext = false;
    StoreMenu storeMenu;
    Ground ground1;
    Ground ground2;
    Player player;
    sf::Packet sendPacket;
    sf::Packet recPacket;
    std::string sendData;
    std::string recData;
    std::vector<Soldier> soldierList;
    std::vector<Tower> towerList;

};

/*
  Restart.deltaTime;
  Rec();
  Update();
  Send();
  Draw();

Update:
BuyMenu() // and UI stuff

Loop{ // all tower with all the soldiers
  Tower[i].Update(Soldier[j], deltaTime);
}
Loop{
  Soldier.Update(deltaTime);
}

Draw:

GroundP1.Draw(window);
GroundP2.Draw(window);
Loop{ // all tower with all the soldiers
  Tower[i].Draw(window);
}
Loop{
  Soldier[i].Draw(window);
}

 */
