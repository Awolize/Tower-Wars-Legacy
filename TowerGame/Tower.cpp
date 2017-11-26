#include "Tower.h" 

Tower::Tower(int type)
{
    Create(int type);
}

Tower::~Tower() {} 

void Tower::Update(float deltaTime)
{
    if (HealthPoints > 0)
    {
	animation.Update(row, deltaTime);
	body.setTextureRect(animation.xyRect);
    }
    else
	body.setPosition(sf::Vector2f(5000,5000));
}

void Tower::Draw(sf::RenderWindow& window)
{
    if(HealthPoints > 0)
	window.draw(body);
}

void Tower::Create(int type)
{
    sf::Texture texture
    if(type == 1)
    {
	texture.loadFromFile("Tower1.png")
	cost = 10;
	range = 3;
	attackSpeed = 0,4;
	reloadTime = 1 / attackspeed;
	damagePoints = 20;
	imageCount = ;
	switchTime = ;
    }
    if(type == 2)
    {
	cost = 20;
	range = 4;
	attackSpeed = 0,8;
	reloadTime = 1 / attackspeed;
	damagePoints = 40;
	imageCount = ;
	switchTime = ;
    }
    body.setTexture(texture);
    body.setPosition(sf::Vector2f(10,10));
}

void Tower::Delete()
{
    while(!Tower_List.empty())
    {
	// Tower_List.pop_back();
    }
}

//ee 
