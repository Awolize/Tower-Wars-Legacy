#include "StoreMenu.h" 

Tower StoreMenu::BuyTower(float Coins, Tower Tower)
{
  if (Player.Coins >= Tower.Cost)
    Player.Coins =- Tower.Cost; 
  return Tower; 
}

Soldier StoreMenu::BuySoldier(float Coins, Soldier Soldier)
{
  if (Player.Coins >= Soldier.Cost)
    Player.Coins =- Soldier.Cost; 
  return Soldier; 
}
