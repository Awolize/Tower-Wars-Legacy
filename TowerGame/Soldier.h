#ifndef SOLDIER_H
#define SOLDIER_H
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Animation.h"
#include "Player.h"
#include <array>
#include <iostream>

class Soldier: public Entity
{
public:
    Soldier(int type, int user, Player & player);
    Soldier(int type);
    void Logic();
    void Update(float deltaTime);
    void Draw(sf::RenderWindow& window) override;
    float getCost() {return cost;};
    float getIncome() {return income;};
    sf::Vector2i getPos() {return tilePos[tileNumber-1];};
    float getTileNumber() {return tileNumber-1;};
    void takeDamage(float damage) {healthPoints -= damage; std::cout << healthPoints << std::endl;};
    bool Alive() {if (healthPoints > 0) return true; else return false;};

private:
    int tileNumber = 0;
    void Create(int type);
    void MoveOneTile();
    float cost = 0;
    float healthPoints = 1;
    float income = 1;
    float moveSpeed = 0;
    float damagePoints = 1; 
    Animation animation; 
    sf::Texture texture;
    sf::Vector2i imageCount = sf::Vector2i(0, 0);
    float switchTime = 0;
    int row = 0;
    int index;
    sf::Clock moveClock;
    float time = 0;
    std::array<sf::Vector2i, 51> tilePos;
    int user = 0;
    float offset;
    bool faceRight = true;
    bool gotTarget = false;
    Player * playerP;
};
#endif

   
