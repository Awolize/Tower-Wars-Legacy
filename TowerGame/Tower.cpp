#include "Tower.h" 

Tower::Tower(int type)
{
    Create(type);
}

Tower::~Tower() {} 

void Tower::Update(float deltaTime)
{
    if (true)
    {
//	animation.Update(row, deltaTime);
//	body.setTextureRect(animation.xyRect);
    }
    else
	body.setPosition(sf::Vector2f(5000,5000));
}

void Tower::Draw(sf::RenderWindow& window)
{
    if(true)
	window.draw(body);
}

void Tower::Create(int type)
{
    if(type == 1)
    {
	texture.loadFromFile("Tower1.png");
	cost = 10;
	range = 3;
	attackSpeed = 0,4;
	reloadTime = 1 / attackSpeed;
	damagePoints = 20;
	imageCount = 0;
	switchTime = 0;
	row = 0;
    }
    if(type == 2)
    {
	texture.loadFromFile("Tower1.png");
	cost = 20;
	range = 4;
	attackSpeed = 0,8;
	reloadTime = 1 / attackSpeed;
	damagePoints = 40;
	imageCount = 0;
	switchTime = 0;
    }
    body.setTexture(&texture);
    body.setPosition(sf::Vector2f(10,10));
}

void Tower::Delete()
{

}
