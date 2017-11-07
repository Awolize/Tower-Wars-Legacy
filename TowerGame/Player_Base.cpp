#include "Player_Base.h"

Player_Base::Player_Base(sf::vector2f PositionXY, float BaseHealthPoints, sf::Texture* BaseTexture)
  : PositionXY(PositionXY), BaseHealthPoints(BaseHealthPoints), BaseTexture(BaseTexture)
{
  //body.setTexture(BaseTexture);
};

Player_Base::~Player_base() {}


void Player_Base::Update(float Time)
{
  if(isDestroyed)
  {
    // Player lost
  }


}
