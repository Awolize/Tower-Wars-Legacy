#include "Soldier.h"
#include <iostream>

using namespace std;

Soldier::Soldier(int type, int index) : index(index)
{
    Create(type);
    tilePos[0] = sf::Vector2i(3,0);    tilePos[1] = sf::Vector2i(3,1);    tilePos[2] = sf::Vector2i(2,1);
    tilePos[3] = sf::Vector2i(1,1);    tilePos[4] = sf::Vector2i(1,2);    tilePos[5] = sf::Vector2i(1,3);
    tilePos[6] = sf::Vector2i(1,4);    tilePos[7] = sf::Vector2i(1,5);    tilePos[8] = sf::Vector2i(1,6);
    tilePos[9] = sf::Vector2i(2,6);    tilePos[10] = sf::Vector2i(3,6);    tilePos[11] = sf::Vector2i(4,6);
    tilePos[12] = sf::Vector2i(4,5);    tilePos[13] = sf::Vector2i(4,4);    tilePos[14] = sf::Vector2i(5,4);
    tilePos[15] = sf::Vector2i(6,4);    tilePos[16] = sf::Vector2i(6,5);    tilePos[17] = sf::Vector2i(6,6);
    tilePos[18] = sf::Vector2i(6,7);    tilePos[19] = sf::Vector2i(6,8);    tilePos[20] = sf::Vector2i(6,9);
    tilePos[21] = sf::Vector2i(5,9);    tilePos[22] = sf::Vector2i(4,9);    tilePos[23] = sf::Vector2i(3,9);
    tilePos[24] = sf::Vector2i(2,9);    tilePos[25] = sf::Vector2i(1,9);    tilePos[26] = sf::Vector2i(1,10);
    tilePos[27] = sf::Vector2i(1,11);    tilePos[28] = sf::Vector2i(1,12);    tilePos[29] = sf::Vector2i(2,12);
    tilePos[30] = sf::Vector2i(3,12);    tilePos[31] = sf::Vector2i(4,12);    tilePos[32] = sf::Vector2i(5,12);
    tilePos[33] = sf::Vector2i(5,12);    tilePos[34] = sf::Vector2i(6,12);    tilePos[35] = sf::Vector2i(7,12);
    tilePos[36] = sf::Vector2i(8,12);    tilePos[37] = sf::Vector2i(8,11);    tilePos[38] = sf::Vector2i(8,11);
    tilePos[39] = sf::Vector2i(8,10);    tilePos[40] = sf::Vector2i(8,9);    tilePos[41] = sf::Vector2i(8,8);
    tilePos[42] = sf::Vector2i(8,7);    tilePos[43] = sf::Vector2i(8,6);    tilePos[44] = sf::Vector2i(8,5);
    tilePos[45] = sf::Vector2i(8,4);    tilePos[46] = sf::Vector2i(8,3);    tilePos[47] = sf::Vector2i(8,2);
    tilePos[48] = sf::Vector2i(8,1);    tilePos[49] = sf::Vector2i(7,1);    tilePos[50] = sf::Vector2i(6,1);
    tilePos[51] = sf::Vector2i(6,0);
}


Soldier::~Soldier() {}

void Soldier::Update(float deltaTime)
{
    if (healthPoints > 0)
    {
//	animation.Update(row, deltaTime);
//	body.setTextureRect(animation.xyRect);  
// 	sf::Time time = moveClock.getElapsedTime();
//	if(time.asMilliseconds() >= 400)
	time += deltaTime;
	if (time > 5)
	{
	    Logic();
	    cout << "Tid: " << time << endl;
	    time = 0;
	}
    }
    else 
	cout << "DÖD!" << endl;
}


void Soldier::Draw(sf::RenderWindow& window)
{
    if(healthPoints > 0)
    {
	window.draw(body);
    }
}

void Soldier::Logic()
{
    tileNumber++;
    float tempPosx = tilePos[tileNumber].x;
    float tempPosy = tilePos[tileNumber].y;
    cout << "x, y: "  << tilePos[tileNumber].x << tilePos[tileNumber].y;
    body.setPosition(sf::Vector2f(tempPosx*60.0f, tempPosy*60.0f));
}

void Soldier::Create(int type)
{
    
    if(type == 1) // change values
    {
	texture.loadFromFile("images/Soldier1.png");
	cost = 10;
	healthPoints = 100;
	damagePoints = 20;
	imageCount = 0;
	switchTime = 0;
	row = 0;
	income = 2;
	moveSpeed = 2;
	tileNumber = 0;
	
    }
    if(type == 2) // change values
    {
	texture.loadFromFile("images/Soldier2.png");
	cost = 10;
	healthPoints = 1;
	damagePoints = 20;
	imageCount = 0;
	switchTime = 0;
	row = 0;
	income = 2;
	moveSpeed = 2;
	tileNumber = 0;
    }
    moveClock.restart();
    body.setTexture(&texture);
    body.setPosition(sf::Vector2f(3*60,0*60));
}

void Soldier::Delete()
{


}
