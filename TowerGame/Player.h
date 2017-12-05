#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <vector>
#include <string>
#include <iostream>

class Player 
{
public: 
    Player();
    void Update();
    float getCoins() {return coins;};
    float getIncome() {return income;};
    void BuyWithCoins(float cost, float increaseIncome);
    void Draw(sf::RenderWindow& window);
    void TakeDamage(int user, int incommingDamage);
    bool GameOver()  { if (baseHealthP1 > 0 && baseHealthP2 > 0) return false; else true; };
    int getWinner();
private:
    void TimerForIncome();
    void createBase();
    void createPortal();
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
    sf::RectangleShape base, enemybase;
    sf::Texture baseTexture, enemybaseTexture;
    sf::RectangleShape portal;
    sf::RectangleShape enemyportal;
    sf::Texture portalTexture;
    int baseHealthP1 { 100 };
    int baseHealthP2 { 100 };
};


#endif
