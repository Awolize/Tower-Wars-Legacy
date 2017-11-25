#include "Tower.h" 

Tower::Tower(float HealthPoints, float Cost, float DamagePoints, float Range, sf::Vector2f Position,
	     sf::Vector2i imageCount, float switchTime, sf::Texture* TowerTexture)
  :Entity(Position), animation(TowerTexture, imageCount, switchTime), 
   HealthPoints{HealthPoints}, Cost{Cost}, DamagePoints{DamagePoints}, Range{Range}
 {
   body.setTexture(TowerTexture);
 }

Tower::~Tower() {} 

void Tower::Update(float deltaTime)
{
  if (HealthPoints > 0)
    {
      animation.Update(row, deltaTime);
      body.setTextureRect(animation.xyRect);
    }
}

void Tower::Draw(sf::RenderWindow& window)
{
  if(HealthPoints > 0)
    {
      window.draw(body);
    }
}

void Tower::Create(int type, sf::Texture& TowerText)
{
  if(type == 1)
    {
      // Tower_List.push_back(Tower(3.0f, 2.0f, 2.0f, sf::Vector2f(0, 0), sf::Vector2i(3, 4), 0.2f, &TowerText));
    }

  if(type == 2)
    {
      // Tower_List.push_back(Tower(3.0f, 2.0f, 2.0f, sf::Vector2f(100, 0), sf::Vector2i(3, 4), 0.2f, &TowerText));   
    }
}

void Tower::Delete()
{
  while(!Tower_List.empty())
    {
      // Tower_List.pop_back();
    }
}

//ee 
