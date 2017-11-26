#include "Soldier.h"

using namespace std;

Soldier::Soldier(int type)
{
    Create(type);
}


Soldier::~Soldier() {}

void Soldier::Update(float deltaTime)
{
    if (healthPoints > 0)
    {
//	animation.Update(row, deltaTime);
//	body.setTextureRect(animation.xyRect);
	//body.move(deltaTime);
    }
  
}


void Soldier::Draw(sf::RenderWindow& window)
{
    if(healthPoints > 0)
    {
	window.draw(body);
    }

}

void Soldier::Intelligence(sf::Vector2f Distance)
{
}

void Soldier::Create(int type)
{
    if(type == 1) // change values
    {
	texture.loadFromFile("Soldier1.png");
	cost = 10;
	healthPoints = 1;
	damagePoints = 20;
	imageCount = 0;
	switchTime = 0;
	row = 0;
	income = 2;
	moveSpeed = 2;
    }
    if(type == 2) // not done
    {
	texture.loadFromFile("Soldier1.png");
	cost = 10;
	healthPoints = 1;
	damagePoints = 20;
	imageCount = 0;
	switchTime = 0;
	row = 0;
	income = 2;
	moveSpeed = 2;
    }
    body.setTexture(&texture);
    body.setPosition(sf::Vector2f(10,10));

}

void Soldier::Delete()
{


}
