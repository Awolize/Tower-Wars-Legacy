#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <vector>
#include <string>
#include <iostream>
#include "Soldier.h"
//#include "Client.h"

class Player 
{
public: 
    Player();
    //~Player();
    void AddIncome();
    void TimerForIncome();
    //void UpdateEconomy(float currCoin, float currIncome);
    void DrawEconomy(sf::RenderWindow & window);
    float getCoins() {return coins;};
    float getIncome() {return income;};
    void BuyWithCoins(float cost, float increaseIncome);
    void createBase();
    void createPortal();
    void drawBase(sf::RenderWindow& window);
    void drawPortal(sf::RenderWindow& window);
private:
    void DefineEconomyMisc();
    //void TimerForIncome(sf::Clock timer);
    void UpdateEconomy();
    sf::Text IncomeValue;
    sf::Text IncomeText;
    sf::Text CoinsValue;
    sf::Text CoinsText;
    sf::FloatRect textRect;
    sf::Font font;
    float coins; 
    float income;
    sf::Sprite economySprite;
    sf::Texture economyTexure;
    sf::RectangleShape coinRectangle;
    sf::RectangleShape incomeRectangle;
    sf::Clock clock;
    sf::RectangleShape base;
    sf::Texture baseTexture;
    sf::RectangleShape portal;
    sf::Texture portalTexture;
    int baseHealth { 100 };

};


#endif
