#ifndef SOLDIER_H
#define SOLDIER_H
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Animation.h"
#include <array>
//#include "Ground.h"

class Soldier: public Entity
{
public:
    //Behöver lägga till Imagecount
    Soldier(int type, int index);
    ~Soldier();

    void Logic();
    void Update(float deltaTime);
    void Draw(sf::RenderWindow& window) override;
    void Delete();
    float GetCost() {return cost;};
    float GetIncome() {return income;};

private:
    void MoveOneTile();
    void Create(int type);
    float cost {0};
    int row{ 0 };
    float healthPoints{ 3 };
    float income{ 2 };
    float moveSpeed{ 2 };
    float damagePoints {0}; 
//    Animation animation; 
    sf::Texture texture;
    float imageCount = 0;
    float switchTime = 0;
    int index;
    sf::Clock moveClock;
    int tileNumber;
    // Ground ground;
    std::array<sf::Vector2i,51> tilePos;
 

};
#endif

//51 tiles för soldier

/*
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

 */