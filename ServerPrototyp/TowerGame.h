#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>

class TowerGame
{
public:
    TowerGame();
    ~TowerGame();
    void Run();
private:
    void MainMenu(sf::RenderWindow &window);
  
};
