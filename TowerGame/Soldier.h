#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"

class Soldier: public Entity
{
public:
  //Behöver lägga till Imagecount från amnimation sen
  Soldier(float HealthPoints, float Income, float MoveSpeed,
	  sf::Vector2f Position);
  ~Soldier();

  void Intelligence(sf::Vector2f Distance);
  void Update(float deltaTime) override;
  void Draw(sf::RenderWindow& window) override;

private:

  int row{ 0 };
  float HealthPoints{ 3 };
  float Income{ 2 };
  float MoveSpeed{ 2 };
  sf::Texture SoldierTexture;
  //Animation
 

};
