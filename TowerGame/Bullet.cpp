#include "Bullet.h"

Bullet::Bullet(int type, sf::Vector2i cPos, sf::Vector2i tPos, float angle, int offset) : cPos(cPos), tPos(tPos), offset(offset)
{
    body.setSize(sf::Vector2f(25, 10));
    body.setOrigin(body.getSize() / 2.0f);
    body.setPosition(cPos.x * 60 + offset, cPos.y * 60);
    body.move(30, 30);
    nPos = cPos - tPos;
    if (type == 1)
    {
	body.setFillColor(sf::Color::Blue);
	bulletTexture.loadFromFile("images/bullet1.png");
    }
    else 
    {
	body.setFillColor(sf::Color::Transparent);
	bulletTexture.loadFromFile("images/bullet2.png");
    }
    body.setTexture(&bulletTexture);
    body.rotate(angle);
}

void Bullet::Draw(sf::RenderWindow& window)
{
    if(!bulletHit)
	window.draw(body);
}

void Bullet::Update(float deltaTime)
{
    if(!bulletHit)
    {
	pos = body.getPosition();
	cPos = sf::Vector2i((pos.x - offset) / 60, pos.y / 60);
	body.move(-nPos.x * deltaTime * 500, -nPos.y * deltaTime * 500);
	if (cPos.x == tPos.x && cPos.y == tPos.y)
	    bulletHit = true;
    }
}

