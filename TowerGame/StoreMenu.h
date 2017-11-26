#ifndef STOREMENU_H
#define STOREMENU_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Tower.h"
#include "Soldier.h"
#include "Player.h"
class StoreMenu
{
public:
    Tower BuyTower(float, Tower, Player); 
    Soldier BuySoldier(float, Soldier, Player);
    void DefineTexture();
    void DrawStoreMenu(sf::RenderWindow & window);
    void StoreMenuLogic(sf::RenderWindow & windo);
private:
    sf::Sprite StoreMenuSprite; 
    sf::Texture StoreMenuTexture;
    sf::RectangleShape OptOne;
    sf::RectangleShape OptTwo;
    sf::RectangleShape OptThree;
    sf::RectangleShape OptFour;
    sf::RectangleShape OptFive;
    sf::RectangleShape OptSix;
    sf::RectangleShape StylingOne;
    sf::RectangleShape StylingTwo;
    bool oneTime = true;
};

#endif
