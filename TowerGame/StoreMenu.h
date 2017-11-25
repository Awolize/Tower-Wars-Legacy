#ifndef STOREMENU_H
#define STOREMENU_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include "Tower.h"
#include "Soldier.h"
#include "Player.h"

class StoreMenu
{
  Tower BuyTower(float, Tower, Player); 
  Soldier BuySoldier(float, Soldier, Player); 
  void DrawStoreMenu(sf::RenderWindow & window); 
  
 
};

#endif
