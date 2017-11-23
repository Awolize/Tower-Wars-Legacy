#ifndef STOREMENU_H
#define STOREMENU_H
#include "Tower.h"
#include "Soldier.h"
#include "Player.h"

class StoreMenu
{
  Tower BuyTower(float, Tower); 
  Soldier BuySoldier(float, Soldier); 
};

#endif
