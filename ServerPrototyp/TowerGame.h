#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>


class TowerGame
{
public:
    TowerGame(sf::RenderWindow &window, sf::TcpSocket &socket) : window(window), socket(socket) {};

    void RunGame();
private:
    void Update();
    void Draw();

    sf::RenderWindow &window;
    sf::TcpSocket &socket;
    float deltaTime = 0.0f;
    sf::Clock clock;
};