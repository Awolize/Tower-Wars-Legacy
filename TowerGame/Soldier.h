#ifndef SOLDIER_H
#define SOLDIER_H
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Animation.h"

class Soldier: public Entity
{
public:
    //Behöver lägga till Imagecount
    Soldier(int type);
    ~Soldier();

    void Intelligence(sf::Vector2f Distance);
    void Update(float deltaTime) override;
    void Draw(sf::RenderWindow& window) override;
    void Delete();
    float GetCost() {return cost;};

private:
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
 

};
#endif
