#ifndef ENTITY_H
#define ENTITY_H
#include <SFML/Graphics.hpp>

class Entity
{
public:
<<<<<<< HEAD
    Entity();
    Entity(sf::Vector2f position);
    ~Entity();
    virtual void Update(float deltaTime) = 0;
    virtual void Draw(sf::RenderWindow &window) = 0;
    sf::RectangleShape body;
=======
  Entity();
  Entity(sf::Vector2f position);
  ~Entity();
  
  virtual void Update(float deltaTime) = 0;
  virtual void Draw(sf::RenderWindow& window) = 0;

  sf::RectangleShape body;
  
>>>>>>> cf87a72393a891746e61fbdaa14f090e64f1ae07
};

#endif
