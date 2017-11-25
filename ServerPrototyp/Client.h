#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>

class Client
{
public:
    Client(sf::RenderWindow &window, sf::TcpSocket &socket) 
    : window(window), socket(socket) {};

    void RunClient();
private:
    void Update();
    void Draw();

    sf::RenderWindow &window;
    sf::TcpSocket &socket;
    float deltaTime = 0.0f;
    sf::Clock clock;
};
