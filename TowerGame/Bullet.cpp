#include "Bullet.h"

using namespace std;

Bullet::Bullet(int type, sf::Vector2i position, float angle)
{
    bulletTexture.loadFromFile("images/bullet.png");
    body.setTexture(&bulletTexture);

    body.setSize(sf::Vector2f(25, 25));
    body.setOrigin(body.getSize() / 2.0f);
    body.setPosition(position.x*60, position.y*60);

    //  body.rotate(-angle);
}

void Bullet::Draw(sf::RenderWindow& window)
{
    window.draw(body);
}

void Bullet::Update(float deltaTime, sf::Vector2i soldierPos)
{
    if(fireReady)
    {
	cout << "soldierPos.x: " <<  soldierPos.x << endl; 

	body.move(soldierPos.x*60, soldierPos.y*60);
    }

}

