#include <iostream>
#include "Animation.h"
#include "Entity.h"
#include "Ground.h"
#include "Soldier.h"
#include "Tower.h"
#include "World.h"
#include "Player.h"
#include <SFML/Graphics.hpp>

using namespace std;

int main()
{
sf::RenderWindow window(sf::VideoMode(1024, 1080), "TowerWars Legacy", sf::Style::Close | sf::Style::Resize);
sf::View TestView(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(1024.0f, 1080.0f));

sf::Texture SoldierText;
SoldierText.loadFromFile("images/playerTexture.png");

window.setVerticalSyncEnabled(true);

//testing soldier
Soldier soldier(3.0f, 2.0f, 2.0f, sf::Vector2f(0, 0), sf::Vector2i(3, 4), 0.2f, &SoldierText);


float deltaTime = 0.0f;
sf::Clock clock;
sf::Time totalTime = sf::seconds(0);
  
while(window.isOpen())
{
  sf::Event event;
  while (window.pollEvent(event))
  {
    switch (event.type)
    {
    case sf::Event::Closed:
      window.close();
      break;
    }
    
    if(event.key.code == sf::Keyboard::Num1)
    {
      soldier.Create(1, SoldierText);
    }

    if(event.key.code == sf::Keyboard::Num2)
    {
      soldier.Create(2, SoldierText);
    }
    
  }

  deltaTime = clock.restart().asSeconds();

  if (deltaTime > 1.0f / 60.0f)
    deltaTime = 1.0f / 60.0f;

  window.clear(sf::Color(0, 0, 0));
 for(Soldier & soldier : soldier.Soldier_List)
  {
    soldier.Update(deltaTime);
    soldier.Draw(window);
  }

  window.setView(TestView);
  window.display();
    
    


}
return 0;
}
