#include "Ground.h"

Ground::Ground()
{
    GroundText.loadFromFile("images/map.png");
    background.setTexture(GroundText);

    int g = 0; // grass
    int r = 1; // road
  
    for (int i = 0; i < grid.size(); i++)
	for (int j = 0; j < grid.at(i).size(); j++)
	{
	    if (j == 0 && (i == 3 || i == 5))
		grid.at(i).at(j) = r;
	    else if (j == 1 && (i == 1 || i == 2 || i == 3 || i == 5 || i == 6 || i == 7 || i == 8))
		grid.at(i).at(j) = r;
	    else if (j == 2 && (i == 1 || i == 8))
		grid.at(i).at(j) = r;
	    else if (j == 3 && (i == 1 || i == 8))
		grid.at(i).at(j) = r;
	    else if (j == 4 && (i == 1 || i == 4 || i == 5 || i == 6 || i == 8))
		grid.at(i).at(j) = r;
	    else if (j == 5 && (i == 1 || i == 4 || i == 6 || i == 8))
		grid.at(i).at(j) = r;
	    else if (j == 6 && (i == 1 || i == 2 || i == 3 || i == 4 || i == 6 || i == 8))
		grid.at(i).at(j) = r;
	    else if (j == 7 && (i == 6 || i == 8))
		grid.at(i).at(j) = r;
	    else if (j == 8 && (i == 6 || i == 8))
		grid.at(i).at(j) = r;
	    else if (j == 9 && (i == 1 || i == 2 || i == 3 || i == 4 || i == 5 || i == 6 || i == 8))
		grid.at(i).at(j) = r;
	    else if (j == 10 && (i == 1 || i == 8))
		grid.at(i).at(j) = r;
	    else if (j == 11 && (i == 1 || i == 8))
		grid.at(i).at(j) = r;
	    else if (j == 12 && (i == 1 || i == 2 || i == 3 || i == 4 || i == 5 || i == 6 || i == 7 || i == 8))
		grid.at(i).at(j) = r;
	    else 
		grid.at(i).at(j) = g;
	}
}

void Ground::SellTower(sf::Vector2i pos)
{
    if (grid.at(pos.x).at(pos.y) == 2)
	grid.at(pos.x).at(pos.y) = 0;
}

bool Ground::IsPlacementAvailable(sf::Vector2i pos)
{
    if (pos.x == -1 && pos.y == -1)
	return true;
    else if (grid.at(pos.x).at(pos.y) == 0)
    {
	grid.at(pos.x).at(pos.y) = 2;
	return true;
    }
    else return false;
}

void Ground::Draw(sf::RenderWindow& window)
{
    window.draw(background);
}

void Ground::SetPosition(int x, int y)
{
    background.setPosition(x, y);
}
