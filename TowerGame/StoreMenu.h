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
    void DefineTexture(sf::RenderWindow & window);
    void DrawStoreMenu(sf::RenderWindow & window);
    std::string StoreMenuLogic(sf::RenderWindow & window);
private:
    sf::Font font;
    sf::Text SoldierType1;
    sf::Text SoldierType2;
    sf::Text TowerType1;
    sf::Text TowerType2;
    sf::Text SellTower;
    sf::FloatRect textRect;
    sf::RectangleShape OptOne;
    sf::RectangleShape OptTwo;
    sf::RectangleShape OptThree;
    sf::RectangleShape OptFour;
    sf::RectangleShape OptFive;
    sf::RectangleShape OptSix;
    sf::RectangleShape maphitbox1;
    sf::RectangleShape maphitbox2;

    bool oneTime = true;
    int option = 0;
    sf::Clock clock;
    sf::Time time;
    bool readyRight = true;
    bool readyLeft = true;

    std::string data;

};

#endif
