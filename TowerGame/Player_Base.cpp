#include "Player_Base.h"

Player_Base::Player_Base(sf::Vector2f PositionXY, float BaseHealthPoints)
  : PositionXY(PositionXY), BaseHealthPoints(BaseHealthPoints)
{
  //body.setTexture(BaseTexture);
}

Player_Base::~Player_Base() {}


void Player_Base::Update(float Time)
{
  if(isDestroyed)
  {
    // Player lost
  }


}
