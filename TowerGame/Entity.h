#ifndef ENTITY_H
#define ENTITY_H
#include <SFML/Graphics.hpp>

class Entity
{
public:
  Entity();
  Entity(sf::Vector2f position);
  ~Entity();
  
  virtual void Update(float deltaTime) = 0;
  virtual void Draw(sf::RenderWindow& window) = 0;

  sf::RectangleShape body;
  
};

#endif
