#include "StoreMenu.h" 
#include <sstream>
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
void StoreMenu::DefineTexture(sf::RenderWindow & window)
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

    OptSix.setSize(sf::Vector2f(200, 80));
    OptSix.setPosition(740,940);
    OptSix.setOrigin(sf::Vector2f(OptOne.getSize() / 2.0f));
    OptSix.setFillColor(sf::Color::Black);  

    maphitbox1.setSize(sf::Vector2f(600, 840));
    maphitbox1.setPosition(maphitbox1.getSize().x / 2, maphitbox1.getSize().y / 2);
    maphitbox1.setOrigin(sf::Vector2f(maphitbox1.getSize() / 2.0f));
    maphitbox1.setFillColor(sf::Color::Red);  

    maphitbox2.setSize(sf::Vector2f(600, 840));
    maphitbox2.setPosition(window.getSize().x - maphitbox2.getSize().x / 2, maphitbox2.getSize().y / 2);
    maphitbox2.setOrigin(sf::Vector2f(maphitbox2.getSize() / 2.0f));
    maphitbox2.setFillColor(sf::Color::Blue);  
}

void StoreMenu::DrawStoreMenu(sf::RenderWindow & window)
{
    if(oneTime)
    {
	DefineTexture(window);
	oneTime = false;
    }
    window.draw(StoreMenuSprite);
    window.draw(maphitbox1);
    window.draw(maphitbox2);
    window.draw(OptOne);
    window.draw(OptTwo);
    window.draw(OptThree);
    window.draw(OptFour);
    window.draw(OptFive);
    window.draw(OptSix);
}
string StoreMenu::StoreMenuLogic(sf::RenderWindow & window)
{
    data = "";
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
    

	if (option == 1 || option == 2 || option == 3 || option == 4)
	    if (option == 3 || option == 4)
		data = to_string(option);
	    else if ( sf::Mouse::getPosition(window).x > maphitbox1.getPosition().x - maphitbox1.getSize().x / 2 &&
		      sf::Mouse::getPosition(window).x < maphitbox1.getPosition().x + maphitbox1.getSize().x / 2 &&
		      sf::Mouse::getPosition(window).y > maphitbox1.getPosition().y - maphitbox1.getSize().y / 2 &&
		      sf::Mouse::getPosition(window).y < maphitbox1.getPosition().y + maphitbox1.getSize().y / 2 )
	    {
		stringstream ss;
		ss << option << " (";
		ss << sf::Mouse::getPosition(window).x / 60;
		ss << ",";
		ss << sf::Mouse::getPosition(window).y / 60;
		ss << ") ";
		data = ss.str();
		option = 0;
	    }
    }
    cout << data;
    return data;
}
