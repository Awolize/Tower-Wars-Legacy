#ifndef TOWER_H
#define TOWER_H
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Animation.h" 

class Tower : public Entity 
{
public: 
    Tower(int type);
    ~Tower();
    void Update(float deltaTime) override;
    void Draw(sf::RenderWindow& window); // override;
    void Delete(); 
    float GetCost() {return cost;};

private:
    void Create(int type);
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
  
};
#endif
