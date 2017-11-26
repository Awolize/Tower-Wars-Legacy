#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "StoreMenu.h"
#include <iostream>
#include <vector>

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
     

    sf::Packet sendPacket;
    sf::Packet recPacket;
    std::string sendData;
    std::string recData;
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
