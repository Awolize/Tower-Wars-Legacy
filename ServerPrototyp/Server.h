#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>


class Server
{
public:
    Server(sf::RenderWindow &window, sf::TcpSocket &socketP1, sf::TcpSocket &socketP2) 
    : window(window), socketP1(socketP1), socketP2(socketP2) {};

    void RunServer();
private:
    void Update();
    void Draw();

    sf::RenderWindow &window;
    sf::TcpSocket &socketP1;  
    sf::TcpSocket &socketP2;
    float deltaTime = 0.0f;
    sf::Clock clock;
};