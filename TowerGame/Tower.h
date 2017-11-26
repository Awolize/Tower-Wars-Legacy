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
    void getCost();

private:
    void Create(int type);
    float Cost {0};
    float DamagePoints {0}; 
    float attackSpeed {0};
    float reloadTime {0};
    float Range {0}; 
    Animation animation; 
    int row {0}; 
  
};
#endif
