#ifndef TOWER_H
#define TOWER_H
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Animation.h" 
#include "Soldier.h"

class Tower : public Entity 
{
public: 
    Tower(int type, sf::Vector2i pos, int inded);
    ~Tower();
    void Update(Soldier soldier, float deltaTime);
    void Draw(sf::RenderWindow& window); // override;
    void Delete(); 
    float GetCost() {return cost;};
private:
    void Create(int type, sf::Vector2i pos);
    float cost {0};
    float damagePoints {0}; 
    float attackSpeed {0};
    float reloadTime {0};
    float range {0}; 
//    Animation animation; 
    sf::Texture texture;
    float imageCount = 0;
    float switchTime = 0;
    int row {0}; 
    int index;


};
#endif
