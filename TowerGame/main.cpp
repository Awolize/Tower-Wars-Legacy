#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>

#include "Menu/MainMenu.h"

using namespace std;

int main()
{
    
    sf::RenderWindow window(sf::VideoMode(1280, 1024), "Tower Wars Legacy", sf::Style::Close);
    window.setVerticalSyncEnabled(true);

    MainMenu mainMenu;
    mainMenu.Run(window);
}
