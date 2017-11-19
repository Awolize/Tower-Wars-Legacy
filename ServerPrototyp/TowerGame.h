#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>


class TowerGame
{
public:
    TowerGame(sf::RenderWindow &window, sf::Socket &socket) : window(window), socket(socket) {};

    void RunMatch();
private:
    sf::RenderWindow &window;
    sf::Socket &socket;
};
