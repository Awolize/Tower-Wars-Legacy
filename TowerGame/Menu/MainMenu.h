#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>


class MainMenu
{
public:
    MainMenu();
    ~MainMenu();
    void Run(sf::RenderWindow &window);
private:
    int menuOption = 0;
  
};
