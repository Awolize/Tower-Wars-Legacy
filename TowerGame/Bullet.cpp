#include "Bullet.h"

using namespace std;

Bullet::Bullet(int type, sf::Vector2i cPos, sf::Vector2i tPos, float angle) : cPos(cPos), tPos(tPos)
{
    bulletTexture.loadFromFile("images/bullet.png");
    body.setTexture(&bulletTexture);

    body.setSize(sf::Vector2f(25, 10));
    body.setOrigin(body.getSize() / 2.0f);
    body.setPosition(cPos.x * 60, cPos.y * 60);
    body.move(30, 30);

    nPos = cPos - tPos;
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
	cPos = sf::Vector2i((pos.x / 60), (pos.y / 60));
	body.move(-nPos.x * deltaTime * 500, -nPos.y * deltaTime * 500);
	if (cPos.x == tPos.x && cPos.y == tPos.y)
	    bulletHit = true;
    }

}

