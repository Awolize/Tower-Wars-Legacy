#include "Player_Base.h"

Player_Base::Player_Base(sf::Vector2f PositionXY, float BaseHealthPoints, sf::Texture* BaseTexture, sf::Vector2i imageCount, float switchTime)
    : Entity(PositionXY), BaseHealthPoints(BaseHealthPoints), animation(BaseTexture, imageCount, switchTime)
{
    body.setTexture(BaseTexture);
}

Player_Base::~Player_Base() {}


void Player_Base::Update(float deltaTime)
{
    if(!isDestroyed)
    {
	animation.Update(row, deltaTime);
	body.setTextureRect(animation.xyRect);
	// Player lost
    }
}

void Player_Base::Draw(sf::RenderWindow& window)
{
    if(!isDestroyed)
    {
	window.draw(body);
    }
}
