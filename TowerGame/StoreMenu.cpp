#include "StoreMenu.h" 
using namespace std;

Tower StoreMenu::BuyTower(float Coins, Tower Tower, Player Player)
{
    if (Player.Coins >= Tower.GetCost())
    {
	Player.Coins =- Tower.GetCost(); 
	return Tower;
    } 
}
Soldier StoreMenu::BuySoldier(float Coins, Soldier Soldier, Player Player)
{
    if (Player.Coins >= Soldier.GetCost())
    {
	Player.Coins =- Soldier.GetCost(); 
	return Soldier;
    } 
}
void StoreMenu::DefineTexture()
{
    StoreMenuTexture.loadFromFile("StoreMenu.png");
    StoreMenuSprite.setTexture(StoreMenuTexture);
    StoreMenuSprite.setPosition(120,800);
  
    OptOne.setSize(sf::Vector2f(200, 40));
    OptOne.setPosition(270,870);
    OptOne.setOrigin(sf::Vector2f(OptOne.getSize() / 2.0f));
    OptOne.setFillColor(sf::Color::Transparent);

    OptTwo.setSize(sf::Vector2f(200, 40));
    OptTwo.setPosition(520,870);
    OptTwo.setOrigin(sf::Vector2f(OptOne.getSize() / 2.0f));
    OptTwo.setFillColor(sf::Color::Transparent);

    OptThree.setSize(sf::Vector2f(200, 40));
    OptThree.setPosition(735,870);
    OptThree.setOrigin(sf::Vector2f(OptOne.getSize() / 2.0f));
    OptThree.setFillColor(sf::Color::Transparent);

    OptFour.setSize(sf::Vector2f(200, 40));
    OptFour.setPosition(960,870);
    OptFour.setOrigin(sf::Vector2f(OptOne.getSize() / 2.0f));
    OptFour.setFillColor(sf::Color::Transparent);

    OptFive.setSize(sf::Vector2f(200, 40));
    OptFive.setPosition(250,960);
    OptFive.setOrigin(sf::Vector2f(OptOne.getSize() / 2.0f));
    OptFive.setFillColor(sf::Color::Transparent);

    OptSix.setSize(sf::Vector2f(200, 40));
    OptSix.setPosition(740,960);
    OptSix.setOrigin(sf::Vector2f(OptOne.getSize() / 2.0f));
    OptSix.setFillColor(sf::Color::Black);  
  
}
void StoreMenu::DrawStoreMenu(sf::RenderWindow & window)
{
    if(oneTime)
    {
	DefineTexture();
	oneTime = false;
    }
    window.draw(StoreMenuSprite);
    window.draw(OptOne);
    window.draw(OptTwo);
    window.draw(OptThree);
    window.draw(OptFour);
    window.draw(OptFive);
    window.draw(OptSix);
}
string StoreMenu::StoreMenuLogic(sf::RenderWindow & window)
{
    if (!sf::Mouse::isButtonPressed(sf::Mouse::Right))
	readyRight = true;
    if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
	readyLeft = true;
    
    if (sf::Mouse::isButtonPressed(sf::Mouse::Right) && readyRight)
    {
	readyRight = false;
	option = 0;
    }
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && readyLeft)
    {
	readyLeft = false;
	if ( sf::Mouse::getPosition(window).x > OptOne.getPosition().x - OptOne.getSize().x / 2 &&
	     sf::Mouse::getPosition(window).x < OptOne.getPosition().x + OptOne.getSize().x / 2 &&
	     sf::Mouse::getPosition(window).y > OptOne.getPosition().y - OptOne.getSize().y / 2 &&
	     sf::Mouse::getPosition(window).y < OptOne.getPosition().y + OptOne.getSize().y / 2 )
	{
	    std::cout << "player bought tower type 1" << std::endl;
	    option = 1;
	}
  
	else if ( sf::Mouse::getPosition(window).x > OptTwo.getPosition().x - OptTwo.getSize().x / 2 &&
		  sf::Mouse::getPosition(window).x < OptTwo.getPosition().x + OptTwo.getSize().x / 2 &&
		  sf::Mouse::getPosition(window).y > OptTwo.getPosition().y - OptTwo.getSize().y / 2 &&
		  sf::Mouse::getPosition(window).y < OptTwo.getPosition().y + OptTwo.getSize().y / 2 )
	{
	    std::cout << "player bought tower type 2" << std::endl;
	    option = 2;
	}
  
	else if ( sf::Mouse::getPosition(window).x > OptThree.getPosition().x - OptThree.getSize().x / 2 &&
		  sf::Mouse::getPosition(window).x < OptThree.getPosition().x + OptThree.getSize().x / 2 &&
		  sf::Mouse::getPosition(window).y > OptThree.getPosition().y - OptThree.getSize().y / 2 &&
		  sf::Mouse::getPosition(window).y < OptThree.getPosition().y + OptThree.getSize().y / 2 )
	{
	    std::cout << "player bought soldier type 1" << std::endl;
	    option = 3;    
	}
  
	else if ( sf::Mouse::getPosition(window).x > OptFour.getPosition().x - OptFour.getSize().x / 2 &&
		  sf::Mouse::getPosition(window).x < OptFour.getPosition().x + OptFour.getSize().x / 2 &&
		  sf::Mouse::getPosition(window).y > OptFour.getPosition().y - OptFour.getSize().y / 2 &&
		  sf::Mouse::getPosition(window).y < OptFour.getPosition().y + OptFour.getSize().y / 2 )
	{
	    std::cout << "player bought soldier type 2" << std::endl;
	    option = 4;      
	}
	else  if ( sf::Mouse::getPosition(window).x > OptFive.getPosition().x - OptFive.getSize().x / 2 &&
		   sf::Mouse::getPosition(window).x < OptFive.getPosition().x + OptFive.getSize().x / 2 &&
		   sf::Mouse::getPosition(window).y > OptFive.getPosition().y - OptFive.getSize().y / 2 &&
		   sf::Mouse::getPosition(window).y < OptFive.getPosition().y + OptFive.getSize().y / 2 )
	{
	    std::cout << "player sold marked tower" << std::endl;
	    option = 5;	
	}
    }

    if (option == 2,3 && readyLeft)

    
    string str = "";
    return str;
}

// add en rektangle för left side som är lika stor som mappen(bild)
// placeras på 60*10/2 för att få x mittpunkt
// placeras på 60*14/2 för att få y mittpunkt
// origin = reksize.xy/2
// size.x = 60*10, .y = 60*14 
