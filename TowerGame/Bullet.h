#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include "Entity.h"

class Bullet : public Entity
{
public:
    Bullet(int type, sf::Vector2i cPos, sf::Vector2i tPos, float angle);
    void Draw(sf::RenderWindow& window) override;
    void Update(float deltaTime);

private:
    sf::Texture bulletTexture;
    bool bulletHit = false;
    sf::Vector2f pos;
    sf::Vector2i cPos;
    sf::Vector2i tPos;
    sf::Vector2i nPos;
};
