#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "Ground.h"
#include "Tower.h"
#include "Soldier.h"
#include <iostream>


Ground::Ground()
{
    GroundText.loadFromFile("images/map.png");
    background.setTexture(GroundText);
    // background.setPosition(0, 0);
    int g = 0; // grass
    int r = 1; // road
  

  
    for (int i = 0; i < grid.size(); i++)
	for (int j = 0; j < grid.at(i).size(); j++)
	{
	    if (j == 0 && i == 3,5)
		grid.at(i).at(j) = r;
	    else if (j == 1 && i == 1,2,3,5,6,7,8)
		grid.at(i).at(j) = r;
	    else if (j == 2 && i == 1,8)
		grid.at(i).at(j) = r;
	    else if (j == 3 && i == 1,8)
		grid.at(i).at(j) = r;
	    else if (j == 4 && i == 1,4,5,6,8)
		grid.at(i).at(j) = r;
	    else if (j == 5 && i == 1,4,6,8)
		grid.at(i).at(j) = r;
	    else if (j == 6 && i == 1,2,3,4,6,8)
		grid.at(i).at(j) = r;
	    else if (j == 7 && i == 6,8)
		grid.at(i).at(j) = r;
	    else if (j == 8 && i == 6,8)
		grid.at(i).at(j) = r;
	    else if (j == 9 && i == 1,2,3,4,5,6,8)
		grid.at(i).at(j) = r;
	    else if (j == 10 && i == 1,8)
		grid.at(i).at(j) = r;
	    else if (j == 11 && i == 1,8)
		grid.at(i).at(j) = r;
	    else if (j == 12 && i == 1,2,3,4,5,6,7,8)
		grid.at(i).at(j) = r;
	    else 
		grid.at(i).at(j) = g;
	}
  
}

void Ground::AddTower(Tower tower)
{

}

void Ground::RemoveTower(Tower tower)
{

}

void Ground::AddSoldier(Soldier soldier)
{

}

void Ground::MoveSoldier(Soldier soldier)
{
    
}

void Ground::RemoveSoldier(Soldier soldier)
{

}

void Ground::Draw(sf::RenderWindow& window)
{
    window.draw(background);

}

void Ground::SetPosition(int x, int y)
{
    background.setPosition(x, y);
}
