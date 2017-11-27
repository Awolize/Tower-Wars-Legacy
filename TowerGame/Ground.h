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
  void AddTower(Tower tower);
  void RemoveTower(Tower tower);

  void AddSoldier(Soldier soldier);
  void MoveSoldier(Soldier soldier);
  void RemoveSoldier(Soldier soldier);
  void Draw(sf::RenderWindow& window);
  void SetPosition(int x, int y);

private:
  std::array<std::array<std::vector<int>, 14>, 10> grid;
  sf::Sprite background;
  sf::Texture GroundText;
};

#endif
