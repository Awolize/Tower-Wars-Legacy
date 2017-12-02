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
    void DefineTexture(sf::RenderWindow & window);
    void Update(sf::RenderWindow & window);
    void CheckButtons(sf::RenderWindow & window);
    void Draw(sf::RenderWindow & window);
    int menuOption = 0;
  
    sf::Font font;
    sf::Text HostGameText;
    sf::FloatRect textRect;
    sf::Text QuitGameText;
    sf::Text JoinGameText;
    sf::RectangleShape HostMenuOption;
    sf::RectangleShape JoinMenuOption;
    sf::RectangleShape QuitMenuOption;
};
