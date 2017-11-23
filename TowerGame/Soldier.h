#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Animation.h"

class Soldier : public Entity
{
public:
  //Behöver lägga till Imagecount från amnimation sen
  Soldier(float HealthPoints, float Income, float MoveSpeed, float Cost,
	  sf::Vector2f Position, sf::Vector2i imageCount, float switchTime,
	  sf::Texture* SoldierTexture);
  ~Soldier();

  void Intelligence(sf::Vector2f Distance);
  void Update(float deltaTime) override;
  void Draw(sf::RenderWindow& window); //override;

  std::vector<Soldier> Soldier_List;
  void Create(int type, sf::Texture& SoldierText);
  void Delete();

  //private:

  int row{ 0 };
  float HealthPoints{ 3 };
  float Income{ 2 };
  float MoveSpeed{ 2 };
  float Cost {0};
  Animation animation;
  //Animation
 

};
