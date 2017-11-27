#include "Player.h"

Player::Player(float coins)
  :coins{coins}, income{10} {

}

/*
void Player::AddIncome();
{
  Coins = Coins + Income;
}

void Player::TimerForIncome(bool cycle)
{

}


void Player::DefineEconomyMisc()
{
  int charsize = 20;
  sf::Font font;
  font.loadFromeFile("Arial.ttf");
  coinRectangle.setSize(sf::Vector2f(200, 40));
  coinRectangle.setPosition(960,960);
  coinRectangle.setOrigin(sf::Vector2f(coinRectangle.getSize() / 2.0f));
  coinRectangle.setFillColor(sf::Color::Black);  

  incomeRectangle.setSize(sf::Vector2f(200, 40));
  incomeRectangle.setPosition(960,1000);
  incomeRectangle.setOrigin(sf::Vector2f(incomeRectangle.getSize() / 2.0f));
  incomeRectangle.setFillColor(sf::Color::Black);  
  sf::FloatRect textRect;
  sf::Text CoinsText;
  CoinsText.setFont(font);
  CoinsText.setCharacterSize(charsize);
  CoinsText.SetFillColor(sf::Color::White);
  CoinsText.setString("Coins");
  CoinsText.setPosition(sf::Vector2f(coinRectangle.getPosition()));
  textRect = CoinText.getLocalBounds();
  sf::Text CoinsValue;
  CoinsValue.setFont(font);
  CoinsValue.setCharacterSize(charsize);
  CoinsValue.SetFillColor(sf::Color::White);
  CoinsValue.setString(coins);
  CoinsValue.setPosition(sf::Vector2f(coinRectangle.getPosition()));
  textRect = CoinsValue.getLocalBounds();

  sf::Text IncomeText;
  IncomeText.setFont(font);
  IncomeText.setCharacterSize(charsize);
  IncomeText.SetFillColor(sf::Color::White);
  IncomeText.setString("Income");
  IncomeText.setPosition(sf::Vector2f(incomeRectangle.getPosition()));
  textRect = IncomeText.getLocalBounds();

  sf::Text IncomeValue;
  IncomeValue.setFont(font);
  IncomeValue.setCharacterSize(charsize);
  IncomeValuet.SetFillColor(sf::Color::White);
  IncomeValue.setString(income);
  IncomeValue.setPosition(sf::Vector2f(incomeRectangle.getPosition()));
  textRect = IncomeValue.getLocalBounds();

  



}
*/
/*
void Player::DrawEconomy(sf::renderwindow & window)
{ 
  window.draw(incomeRectangle);
  window.draw(incomeRectangle);
  window.draw(incomeRectangle);
  window.draw(incomeRectangle);

}
*/
void Player::BuyWithCoins(float money)
{
  coins =- money;
}

float Player::GetCoins()
{
  return coins;
}


void Player::UpdateEconomy(float currCoin, float currIncome)
{
  income = currIncome;
  coins = currCoin;
}
