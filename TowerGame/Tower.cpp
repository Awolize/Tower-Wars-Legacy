#include "Tower.h" 

Tower::Tower(int type, sf::Vector2i pos, int index) : index(index)
{
    Create(type, pos);
}

Tower::~Tower() {} 

void Tower::Update(Soldier & soldier, float deltaTime)
{
    if (false)
    {
//	animation.Update(row, deltaTime);
//	body.setTextureRect(animation.xyRect);
    }
    else
	body.setPosition(sf::Vector2f(100, 500));
   
}

void Tower::Draw(sf::RenderWindow& window)
{
    if(true)
	window.draw(body);
}

void Tower::Create(int type, sf::Vector2i pos)
{
    if(type == 1)
    {
	texture.loadFromFile("t1.png");
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
	texture.loadFromFile("images/Tower2.png");
	cost = 20;
	range = 4;
	attackSpeed = 0,8;
	reloadTime = 1 / attackSpeed;
	damagePoints = 40;
	imageCount = 0;
	switchTime = 0;
    }
    body.setPosition(sf::Vector2f(pos));
    body.setTexture(&texture);
}

void Tower::Delete()
{

}
