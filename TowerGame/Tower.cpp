#include "Tower.h"

#include <iostream>


using namespace std;

Tower::Tower(int type, sf::Vector2i pos, int user) : user(user), pos(pos)
{
    if (user == 1)
	offset = 0;
    else if (user == 2)
	offset = 60 * 10 + 80;
    soldierP = NULL;
    Create(type);
    bulletType = type;
}


Tower::Tower(int type)
{
    if (type == 1) 
	cost = 10;
    if (type == 2) 
	cost = 20;
}

void Tower::Update(float deltaTime)
{   
    time += deltaTime;
    for(Bullet & bullet : bulletList)
	bullet.Update(deltaTime);
    if(soldierP != NULL && gotTarget())
    {
	body.rotate(-angle);
	angle = atan2(pos.y - soldierP->getPos().y, pos.x - soldierP->getPos().x);
	angle = angle*180/3.14159265359;
	body.rotate(angle);

	
	if (time > reloadTime)
	{
	    bulletList.push_back(Bullet(bulletType, getPos(), soldierP->getPos(), angle, offset));

	    soldierP->takeDamage(damagePoints);
	    time = 0;
	    if(!soldierP->Alive())
		soldierP = NULL;
	}
    }
    body.setTexture(&texture);
}

bool Tower::gotTarget()
{
    if (soldierP != NULL)
	if (soldierP->Alive())
	    if (inRange())
		return true;
    return false;
}

void Tower::getTarget(Soldier & soldier)
{
    if (soldierP == NULL)
	soldierP = &soldier;
    else if (!inRange())
	soldierP = &soldier;
    else if (soldier.getTileNumber() > soldierP->getTileNumber())
	soldierP = &soldier;
}

bool Tower::inRange()
{
    if (soldierP->getPos().x < pos.x + range &&
	soldierP->getPos().x > pos.x - range && 
	soldierP->getPos().y < pos.y + range &&
	soldierP->getPos().y > pos.y - range)
	return true;
    
    return false;
}

void Tower::Draw(sf::RenderWindow& window)
{    
    for(Bullet & bullet : bulletList)
    {
	bullet.Draw(window);
    }
    if(true)
	window.draw(body);
}

void Tower::Create(int type)
{
    if(type == 1)
    {
	texture.loadFromFile("images/Tower1.png");
	cost = 10;
	range = 2;
	attackSpeed = 0.4;
	reloadTime = 1 / attackSpeed;
	damagePoints = 20.0000001;
    }
    if(type == 2)
    {
	texture.loadFromFile("images/Tower2.png");
	cost = 20;
	range = 4;
	attackSpeed = 0.8;
	reloadTime = 1 / attackSpeed;
	damagePoints = 40.0000001;
    }
    body.setSize(sf::Vector2f(50, 50));
    body.setOrigin(body.getSize() / 2.0f);
    body.setPosition(sf::Vector2f(pos * 60));
    body.move(sf::Vector2f(30 + offset, 30));
    body.setTexture(&texture);
    body.rotate(-90);
}
