#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
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

    sf::Packet sendPacket;
    sf::Packet recPacket;
    std::string sendData;
    std::string recData;
};
