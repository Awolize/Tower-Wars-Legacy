#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include "Animation.h"
#include "Entity.h"

class Bullet : public Entity
{
public:
    Bullet(int type);
    ~Bullet();
    void Draw(sf::RenderWindow& window) override;
    void Update(float deltaTime);
    


private:
    sf::Texture bulletTexture;
    // sf::Vector2i imageCount = sf::Vector2i(0, 0);
    //  float switchTime = 0;
    // int row = 0;
    //   Animation animation;

};
