#include "Bullet.h"

using namespace std;

Bullet::Bullet(int type)
{
    body.setSize(sf::Vector2f(25, 25));
    body.setOrigin(sf::Vector2f(body.getSize() / 2.0f));

    if(type == 1)
	bulletTexture.loadFromFile("images/bullet1.png");
    else
	bulletTexture.loadFromFile("images/bullet2.png");

    // imageCount = sf::Vector2i(3, 2);
    //  switchTime = 2.f;
    body.setTexture(&bulletTexture);
    //animation.Create(&bulletTexture, imageCount, switchTime);
}

Bullet::~Bullet() {}


void Bullet::Draw(sf::RenderWindow& window)
{
    window.draw(body);
}

void Bullet::Update(float deltaTime)
{
    //animation.Update(row, deltaTime);
}
