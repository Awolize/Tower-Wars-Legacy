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
    std::string strRequest();
    void SendDataToServer(std::string option);
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
    std::vector<Soldier> soldierListP1;
    std::vector<Tower> towerListP1;
    std::vector<Soldier> soldierListP2;
    std::vector<Tower> towerListP2;
	sf::Font font;
	sf::Text text;
};
