#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <vector>
#include <iostream>

class Player 
{
 public: 
  Player(float Coins);
  ~Player();
  //void AddIncome();
  //void TimerForIncome(bool cycle);
  void UpdateEconomy(float currCoin, float currIncome);
  //void DrawEconomy(sf::renderwindow & window);
  float GetCoins();
  void BuyWithCoins(float money);
private:
  void DefineEconomyMisc();
  //void TimerForIncome(sf::Clock timer);
  float coins; 
  float income;
  sf::Sprite economySprite;
  sf::Texture economyTexure;
  sf::RectangleShape coinRectangle;
  sf::RectangleShape incomeRectangle;
  sf::Clock timer;
  sf::Time time;

};


#endif
