#include "Soldier.h"

Soldier::Soldier(float HealthPoints, float Income, float MoveSpeed, sf::Vector2f Position)
  :Entity(Position), HealthPoints{HealthPoints}, Income{Income}, MoveSpeed{MoveSpeed}
 {
//   body.setTexture(SoldierTexture);
 }


Soldier::~Soldier() {}

void Soldier::Update(float deltaTime)
{
}


void Soldier::Draw(sf::RenderWindow& window)
{
}

void Soldier::Intelligence(sf::Vector2f Distance)
{
}
