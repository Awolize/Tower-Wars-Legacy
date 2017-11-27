#include "Player.h"

Player::Player()
    :coins{100}, income{10} {
	DefineEconomyMisc();
		   }


void Player::AddIncome()
{
    coins = coins + income;
}

void Player::TimerForIncome()
{
    clock.restart();
    AddIncome();
}

void Player::UpdateEconomy()
{
    sf::Time time = clock.getElapsedTime();
    if(time.asSeconds() >= 1.0)
	TimerForIncome();
    std::string tempIncome = std::to_string(income);
    std::string tempCoins = std::to_string(coins);
    CoinsValue.setString(tempCoins);
    IncomeValue.setString(tempIncome);
}

void Player::DefineEconomyMisc()
{
    int charsize = 20;

    font.loadFromFile("Arial.ttf");
    coinRectangle.setSize(sf::Vector2f(200, 40));
    coinRectangle.setPosition(900,960);
    coinRectangle.setOrigin(sf::Vector2f(coinRectangle.getSize() / 2.0f));
    coinRectangle.setFillColor(sf::Color::Black);  

    incomeRectangle.setSize(sf::Vector2f(200, 40));
    incomeRectangle.setPosition(900,1000);
    incomeRectangle.setOrigin(sf::Vector2f(incomeRectangle.getSize() / 2.0f));
    incomeRectangle.setFillColor(sf::Color::Black);  


    CoinsText.setFont(font);
    CoinsText.setCharacterSize(charsize);
    CoinsText.setFillColor(sf::Color::White);
    CoinsText.setString("Coins:");
    CoinsText.setPosition(sf::Vector2f(coinRectangle.getPosition()));
    textRect = CoinsText.getLocalBounds();

    std::string tempCoins = std::to_string(coins);
    CoinsValue.setFont(font);
    CoinsValue.setCharacterSize(charsize);
    CoinsValue.setFillColor(sf::Color::White);
    CoinsValue.setString(tempCoins);
    CoinsValue.setPosition(sf::Vector2f(coinRectangle.getPosition().x + 150.f, coinRectangle.getPosition().y));
    textRect = CoinsValue.getLocalBounds();

    IncomeText.setFont(font);
    IncomeText.setCharacterSize(charsize);
    IncomeText.setFillColor(sf::Color::White);
    IncomeText.setString("Income:");
    IncomeText.setPosition(sf::Vector2f(incomeRectangle.getPosition()));
    textRect = IncomeText.getLocalBounds();

    std::string tempIncome = std::to_string(income);
    IncomeValue.setFont(font);
    IncomeValue.setCharacterSize(charsize);
    IncomeValue.setFillColor(sf::Color::White);
    IncomeValue.setString(tempIncome);
    IncomeValue.setPosition(sf::Vector2f(incomeRectangle.getPosition().x + 150.f, incomeRectangle.getPosition().y));
    textRect = IncomeValue.getLocalBounds();
}


void Player::DrawEconomy(sf::RenderWindow & window)
{ 
    UpdateEconomy();
    window.draw(incomeRectangle);
    window.draw(coinRectangle);
    window.draw(IncomeText);
    window.draw(CoinsText);
    window.draw(IncomeValue);
    window.draw(CoinsValue);

}

void Player::BuyWithCoins(float money)
{
    coins = coins - money;
}

float Player::GetCoins()
{
    return coins;
}


