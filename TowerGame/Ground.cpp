#include "Ground.h"

Ground::Ground(sf::vector2f tileSize, int width, int height)
{
    for(int i{0}; i < width; i++) {
	for (int j{0}; j < height; i++)
	    grid[i].push_back(0);
    }   
}
/*
Ground::~Ground()
{

}
*/
void Ground::Update()
{

}

void Ground::Draw(sf::RenderWindow & window)
{


}

void Ground::PlaceTower(int xPosition, int yPosition)
{
    for(std::vector<int>::iterator it = grid.begin(); it != grid.end(); ++it) {
	for(std::vector<int>::iterator it2 = grid[it].begin(); it2 != grid[it].end(); ++it) {
    
	}
    }
}

void Ground::SelectPosition(int xPostion, int yPostion)
{
    for(std::vector<int>::iterator it = grid.begin(); it != grid.end(); ++it) {
	for(std::vector<int>::iterator it2 = grid[it].begin(); it2 != grid[it].end(); ++it) {
    
	}
    }

}

bool Ground::PlacementAvaliable(int xPostion, int yPostion)
{
    for(std::vector<int>::iterator it = grid.begin(); it != grid.end(); ++it) {
	for(std::vector<int>::iterator it2 = grid[it].begin(); it2 != grid[it].end(); ++it) {
    
	}
    }


}

void Ground::SellTower(int xPostion, int yPostion)
{
    for(std::vector<int>::iterator it = grid.begin(); it != grid.end(); ++it) {
    
    }

}

void Ground::UpgradeTower(int xPostion, int yPostion)
{
    for(std::vector<int>::iterator it = grid.begin(); it != grid.end(); ++it) {
	for(std::vector<int>::iterator it2 = grid[it].begin(); it2 != grid[it].end(); ++it) {
    
	}
    }
}


void Ground::GroundTile(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position)
{

}
