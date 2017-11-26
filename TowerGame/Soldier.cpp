#include "Soldier.h"

Soldier::Soldier(float HealthPoints, float Income, float MoveSpeed, sf::Vector2f Position,
		 sf::Vector2i imageCount, float switchTime, sf::Texture* SoldierTexture)
  :Entity(Position), animation(SoldierTexture, imageCount, switchTime), 
   HealthPoints{HealthPoints}, Income{Income}, MoveSpeed{MoveSpeed}
 {
     body.setTexture(SoldierTexture);
 }


Soldier::~Soldier() {}

void Soldier::Update(float deltaTime)
{
  if (HealthPoints > 0)
  {
    animation.Update(row, deltaTime);
    body.setTextureRect(animation.xyRect);
    //body.move(deltaTime);
    
  }
  
}


void Soldier::Draw(sf::RenderWindow& window)
{
  if(HealthPoints > 0)
  {
    window.draw(body);
  }

}

void Soldier::Intelligence(sf::Vector2f Distance)
{
}

void Soldier::Create(int type, sf::Texture& SoldierText)
{
  if(type == 1)
  {
    Soldier_List.push_back(Soldier(3.0f, 2.0f, 2.0f, sf::Vector2f(0, 0), sf::Vector2i(3, 4), 0.2f, &SoldierText));

    //player.money --; 
  }

  if(type == 2)
  {
    Soldier_List.push_back(Soldier(3.0f, 2.0f, 2.0f, sf::Vector2f(100, 0), sf::Vector2i(3, 4), 0.2f, &SoldierText));   
  }

}

void Soldier::Delete()
{
  while(!Soldier_List.empty())
  {
    Soldier_List.pop_back();
  }

}
