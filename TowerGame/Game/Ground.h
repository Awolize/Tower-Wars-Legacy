#ifndef GROUND_H
#define GROUND_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <vector>
#include <iostream>
#include "Tower.h"
#include "Soldier.h"

class Ground
{
public:
    Ground();
    void Insert(sf::Vector2i pos);
    void Draw(sf::RenderWindow& window);
    void SetPosition(int x, int y);
    bool IsPlacementAvailable(sf::Vector2i pos);
private:
    std::array<std::array<int, 14>, 10> grid;
    sf::Sprite background;
    sf::Texture GroundText;
};

#endif
