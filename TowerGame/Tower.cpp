#include "Tower.h"
#include <iostream>

using namespace std;

Tower::Tower(int type, sf::Vector2i pos, int index, int user) : index(index), user(user), pos(pos)
{
    if (user == 1)
	offset = 0;
    else if (user == 2)
	offset = 60 * 10 + 80;
    soldierP = NULL;
    Create(type);
}


Tower::Tower(int type)
{
    if (type == 1) 
	cost = 10;
    if (type == 2) 
	cost = 20;
}

Tower::~Tower() {} 

void Tower::Update(float deltaTime)
{   
    time += deltaTime;
    body.setFillColor(sf::Color::White);
    body.setTexture(&texture);
    if (soldierP != NULL)
	if (time > reloadTime && gotTarget())
	{
	    cout << "SKJUT!" << endl;
	    soldierP->takeDamage(damagePoints);
	    body.setFillColor(sf::Color::Red);
	    time = 0;
	}   
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
    if(true)
	window.draw(body);
}

void Tower::Create(int type)
{
    if(type == 1)
    {
	texture.loadFromFile("images/Tower1.png");
	cost = 10;
	range = 3;
	attackSpeed = 0.4;
	reloadTime = 1 / attackSpeed;
	damagePoints = 50;
    }
    if(type == 2)
    {
	texture.loadFromFile("images/Tower2.png");
	cost = 20;
	range = 4;
	attackSpeed = 0.8;
	reloadTime = 1 / attackSpeed;
	damagePoints = 40;
    }
    body.setSize(sf::Vector2f(50, 50));
    body.setOrigin(body.getSize() / 2.0f);
    body.setPosition(sf::Vector2f(pos * 60));
    body.move(sf::Vector2f(30 + offset, 30));
    body.setTexture(&texture);
}

void Tower::Delete()
{

}
