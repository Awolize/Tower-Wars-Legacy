#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include "ServerGameManager.h"


class Server
{
public:
    Server(sf::RenderWindow &window, sf::TcpSocket &socketP1, sf::TcpSocket &socketP2) 
    : window(window), socketP1(socketP1), socketP2(socketP2) {};

    void RunServer();
    void Update();
    void Draw();
private:


    float deltaTime = 0.0f;
    sf::RenderWindow &window;
    sf::Clock clock;
    sf::Packet packetP1;
    sf::Packet packetP2;
    sf::TcpSocket &socketP1;  
    sf::TcpSocket &socketP2;
    Player player1;
    Player player2;
    Ground groundP1;
    Ground groundP2;
    ServerGameManager SGM;
};
