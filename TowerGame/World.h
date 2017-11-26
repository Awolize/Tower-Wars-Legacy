#pragma once

class World
{
public:
  
  virtual void Render(sf::RenderWindow& window) = 0;
  sf::Time elapsed;

};
