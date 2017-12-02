#include "Tower.h" 

Tower::Tower(int type, sf::Vector2i pos, int index, int user) : index(index), user(user)
{
    Create(type, pos);
}


Tower::Tower(int type)
{
    if (type == 1) 
	cost = 10;
    if (type == 2) 
	cost = 20;
}

Tower::~Tower() {} 

void Tower::Update(Soldier & soldier, float deltaTime)
{
    body.setTexture(&texture);
    if (false)
    {
//	animation.Update(row, deltaTime);
//	body.setTextureRect(animation.xyRect);
    }
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
	texture.loadFromFile("images/Tower1.png");
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
	row = 0;
    }
    body.setSize(sf::Vector2f(50,50));
    body.setOrigin(body.getSize()/2.0f);
    body.setPosition(sf::Vector2f(pos*60));
    body.move(sf::Vector2f(30,30));
    body.setTexture(&texture);
}

void Tower::Delete()
{

}
