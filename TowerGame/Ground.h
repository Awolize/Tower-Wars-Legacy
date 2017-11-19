#pragma once
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Entity.h"


class Ground
{
public:
    Ground(sf::Vector2f tileSize, int width, int height);
    //~Ground();

    void Update();
    void Draw(sf::RenderWindow & window);
    void PlaceTower(int xPosition,int yPosition);
    void SelectPosition(int xPosition,int yPosition);
    bool PlacementAvaliable(int xPosition,int yPosition);
    void SellTower(int xPosition,int yPosition);
    void UpgradeTower(int xPosition,int yPosition);

private:
    sf::Texture texture;
    void GroundTile(sf::Texture* texture,sf::Vector2f size, sf::Vector2f position);
    std::vector<<vector<int> grid;
    sf::RectangleShape tile;
    int placedOnTile;
    
}
