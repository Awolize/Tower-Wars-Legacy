#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include "Entity.h"

class Bullet : public Entity
{
public:
    Bullet(int type, sf::Vector2i position, float angle);
    ~Bullet();
    void Draw(sf::RenderWindow& window) override;
    void Update(float deltaTime, sf::Vector2i soldierPos);
    bool fireReady { false };

private:
    sf::Texture bulletTexture;

};
