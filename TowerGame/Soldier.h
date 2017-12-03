#ifndef SOLDIER_H
#define SOLDIER_H
#include <SFML/Graphics.hpp>
#include "Entity.h"
//#include "Animation.h"
#include <array>

class Soldier: public Entity
{
public:
    Soldier(int type, int index, int user);
    Soldier(int type);
    ~Soldier();

    void Logic();
    void Update(float deltaTime);
    void Draw(sf::RenderWindow& window) override;
    void Delete();

    float getCost() {return cost;};
    float getIncome() {return income;};

private:
    void Create(int type);
    void MoveOneTile();
    float cost;
    float healthPoints;
    float income;
    float moveSpeed;
    float damagePoints; 
//  Animation animation; 
    sf::Texture texture;
    float imageCount = 0;
    float switchTime = 0;
    int row;
    int index;
    sf::Clock moveClock;
    int tileNumber = 0;
    float time = 0;
    std::array<sf::Vector2i, 53> tilePos;
    int user = 0;
    float offset;
};
#endif
