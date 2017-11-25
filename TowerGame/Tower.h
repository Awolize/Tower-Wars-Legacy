#ifndef TOWER_H
#define TOWER_H
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Animation.h" 

class Tower : public Entity 
{
 public: 
  Tower(float HealthPoints, float Cost, float DamagePoints, float Range,
	  sf::Vector2f Position, sf::Vector2i imageCount, float switchTime,
	  sf::Texture* TowerTexture);
  ~Tower();

  void Update(float deltaTime) override;
  void Draw(sf::RenderWindow& window); // override;
  std::vector<Tower> Tower_List; 
  void Create(int type, sf::Texture& TowerText);
  void Delete(); 
 

  // private:
  float HealthPoints {0}; 
  float Cost {0};
  float DamagePoints {0}; 
  float Range {0}; 
  Animation animation; 
  int row {0}; 
  
};
#endif
//eerg
