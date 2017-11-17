#pragma once
#include <SFML/Graphics.hpp>

class Player_Base // : public Player
{
public:

  Player_Base(sf::Vector2f PositionXY, float BaseHealthPoints);
  bool isDestroyed{ false };
  void Update(float Time);
  //on Collision (med soldier) ? --> lose hp --> destroy soldier

  ~Player_Base();
private:
  sf::Vector2f PositionXY;
  float BaseHealthPoints { 100.f };
  sf::Texture BaseTexture;
  
};
