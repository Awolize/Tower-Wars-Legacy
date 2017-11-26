#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Entity.h"

class Player_Base : public Entity // : public Player
{
public:

    Player_Base(sf::Vector2f PositionXY, float BaseHealthPoints, sf::Texture* BaseTexture, sf::Vector2i imageCount,
		float switchTime);
    bool isDestroyed{ false };
    void Update(float deltaTime);
    void Draw(sf::RenderWindow& window) override;
    //on Collision (med soldier) ? --> lose hp --> destroy soldier

    ~Player_Base();
private:
    sf::Vector2f PositionXY;
    float BaseHealthPoints { 100.f };
    Animation animation;
    int row { 0 };
  
};
