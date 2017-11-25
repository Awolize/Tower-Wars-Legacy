#include "StoreMenu.h" 

Tower StoreMenu::BuyTower(float Coins, Tower Tower, Player Player)
{
  if (Player.Coins >= Tower.Cost)
    {
      Player.Coins =- Tower.Cost; 
      return Tower;
    } 
}

Soldier StoreMenu::BuySoldier(float Coins, Soldier Soldier, Player Player)
{
  if (Player.Coins >= Soldier.Cost)
    {
      Player.Coins =- Soldier.Cost; 
      return Soldier;
    } 
}

void StoreMenu::DrawStoreMenu(sf::RenderWindow & window)
{
  //Define texture
  sf::Texture StoreMenuTexture;
  StoreMenuTexture.loadFromFile("storemenu.png");

  //Define sprite for texture
  sf::Sprite StoreMenuSprite; 
  StoreMenuSprite.setTexture(StoreMenuTexture);

  window.draw(StoreMenuSprite);
}
