#include "Soldier.h"
#include <iostream>

using namespace std;

Soldier::Soldier(int type, int index, int user) : index(index), user(user),
						  animation()
{
    if (user == 1)
	offset = 0;
    else if (user == 2)
	offset = 60 * 10 + 80;

    Create(type);
    animation.Create(&texture, imageCount, switchTime);

    tilePos[0] = sf::Vector2i(3,0);      tilePos[1] = sf::Vector2i(3,1);     tilePos[2] = sf::Vector2i(2,1);
    tilePos[3] = sf::Vector2i(1,1);      tilePos[4] = sf::Vector2i(1,2);     tilePos[5] = sf::Vector2i(1,3);
    tilePos[6] = sf::Vector2i(1,4);      tilePos[7] = sf::Vector2i(1,5);     tilePos[8] = sf::Vector2i(1,6);
    tilePos[9] = sf::Vector2i(2,6);      tilePos[10] = sf::Vector2i(3,6);    tilePos[11] = sf::Vector2i(4,6);
    tilePos[12] = sf::Vector2i(4,5);     tilePos[13] = sf::Vector2i(4,4);    tilePos[14] = sf::Vector2i(5,4);
    tilePos[15] = sf::Vector2i(6,4);     tilePos[16] = sf::Vector2i(6,5);    tilePos[17] = sf::Vector2i(6,6);
    tilePos[18] = sf::Vector2i(6,7);     tilePos[19] = sf::Vector2i(6,8);    tilePos[20] = sf::Vector2i(6,9);
    tilePos[21] = sf::Vector2i(5,9);     tilePos[22] = sf::Vector2i(4,9);    tilePos[23] = sf::Vector2i(3,9);
    tilePos[24] = sf::Vector2i(2,9);     tilePos[25] = sf::Vector2i(1,9);    tilePos[26] = sf::Vector2i(1,10);
    tilePos[27] = sf::Vector2i(1,11);    tilePos[28] = sf::Vector2i(1,12);   tilePos[29] = sf::Vector2i(2,12);
    tilePos[30] = sf::Vector2i(3,12);    tilePos[31] = sf::Vector2i(4,12);   tilePos[32] = sf::Vector2i(5,12);
    tilePos[33] = sf::Vector2i(6,12);    tilePos[34] = sf::Vector2i(7,12);    tilePos[35] = sf::Vector2i(8,12); 
    tilePos[36] = sf::Vector2i(8,11);
    tilePos[37] = sf::Vector2i(8,10);    tilePos[38] = sf::Vector2i(8,9);    tilePos[39] = sf::Vector2i(8,8);
    tilePos[40] = sf::Vector2i(8,7);     tilePos[41] = sf::Vector2i(8,6);    tilePos[42] = sf::Vector2i(8,5);
    tilePos[43] = sf::Vector2i(8,4);     tilePos[44] = sf::Vector2i(8,3);    tilePos[45] = sf::Vector2i(8,2);
    tilePos[46] = sf::Vector2i(8,1);     tilePos[47] = sf::Vector2i(7,1);    tilePos[48] = sf::Vector2i(6,1);
    tilePos[49] = sf::Vector2i(5,1);     tilePos[50] = sf::Vector2i(5,0);  
}

Soldier::Soldier(int type)
{
    if (type == 3)
    {
	cost = 10;
	income = 1;
    }	
    else if (type == 4)
    { 
	cost = 20;
	income = 2;
    }
}

Soldier::~Soldier() {}

void Soldier::Update(float deltaTime)
{
    if (Alive())
    {
	time += deltaTime;
	if (time > moveSpeed)
	{
	    Logic();
	    time = 0;
	}

	if (tileNumber > 0)
	    if (tilePos[tileNumber].x < tilePos[tileNumber-1].x)
		row = 1;
	    else 
		row = 0;

	body.setTexture(&texture);
	animation.Update(row, deltaTime);
	body.setTextureRect(animation.xyRect);  
    }
}

void Soldier::Draw(sf::RenderWindow& window)
{
    if (Alive())
	window.draw(body);
}

void Soldier::Logic()
{
    if(tileNumber == 51)
	healthPoints = 0;
    body.setPosition(sf::Vector2f(tilePos[tileNumber] * 60));
    body.move(sf::Vector2f(30 + offset, 30));
    ++tileNumber;
}

void Soldier::Create(int type)
{
    if(type == 3) // change values
    {
	texture.loadFromFile("images/Soldier1.png");
	cost = 10;
	healthPoints = 100;
	damagePoints = 20;
	income = 1;
	moveSpeed = 0.6;
    }
    if(type == 4) // change values
    {
	texture.loadFromFile("images/Soldier2.png");
	cost = 20;
	healthPoints = 100;
	damagePoints = 20;
	income = 2;
	moveSpeed = 1.0;	
    }
    imageCount = sf::Vector2i(3, 2);
    switchTime = moveSpeed / 4;
    body.setSize(sf::Vector2f(50, 50));
    body.setOrigin(body.getSize() / 2.0f);
    body.setPosition(sf::Vector2f(3 * 60, -1 * 60));
    body.move(sf::Vector2f(30 + offset, 30));
    body.setTexture(&texture);
}

void Soldier::Delete()
{


}
