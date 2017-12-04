#include "StoreMenu.h" 
#include <sstream>
using namespace std;

Tower StoreMenu::BuyTower(float Coins, Tower Tower, Player Player)
{
    if (Player.getCoins() >= Tower.getCost())
    {
	Player.BuyWithCoins(Tower.getCost(), 0.f); 
	return Tower;
    } 
}
Soldier StoreMenu::BuySoldier(float Coins, Soldier Soldier, Player Player)
{
    if (Player.getCoins() >= Soldier.getCost())
    {
	Player.BuyWithCoins(Soldier.getCost(), Soldier.getIncome()); 
	return Soldier;
    } 
}
void StoreMenu::DefineTexture(sf::RenderWindow & window)
{ 
    OptOne.setSize(sf::Vector2f(200, 40));
    OptOne.setPosition(160,870);
    OptOne.setOrigin(sf::Vector2f(OptOne.getSize() / 2.0f));
    OptOne.setFillColor(sf::Color::Black);

    OptTwo.setSize(sf::Vector2f(200, 40));
    OptTwo.setPosition(480,870);
    OptTwo.setOrigin(sf::Vector2f(OptOne.getSize() / 2.0f));
    OptTwo.setFillColor(sf::Color::Black);

    OptThree.setSize(sf::Vector2f(200, 40));
    OptThree.setPosition(800,870);
    OptThree.setOrigin(sf::Vector2f(OptOne.getSize() / 2.0f));
    OptThree.setFillColor(sf::Color::Black);

    OptFour.setSize(sf::Vector2f(200, 40));
    OptFour.setPosition(1120,870);
    OptFour.setOrigin(sf::Vector2f(OptOne.getSize() / 2.0f));
    OptFour.setFillColor(sf::Color::Black);

    OptFive.setSize(sf::Vector2f(200, 40));
    OptFive.setPosition(160,940);
    OptFive.setOrigin(sf::Vector2f(OptOne.getSize() / 2.0f));
    OptFive.setFillColor(sf::Color::Black);

    maphitbox1.setSize(sf::Vector2f(600, 840));
    maphitbox1.setPosition(maphitbox1.getSize().x / 2, maphitbox1.getSize().y / 2);
    maphitbox1.setOrigin(sf::Vector2f(maphitbox1.getSize() / 2.0f));
    maphitbox1.setFillColor(sf::Color::Red);  

    maphitbox2.setSize(sf::Vector2f(600, 840));
    maphitbox2.setPosition(window.getSize().x - maphitbox2.getSize().x / 2, maphitbox2.getSize().y / 2);
    maphitbox2.setOrigin(sf::Vector2f(maphitbox2.getSize() / 2.0f));
    maphitbox2.setFillColor(sf::Color::Blue);  

    font.loadFromFile("Arial.ttf");
  
    SoldierType1.setFont(font);
    SoldierType1.setString("Buy soldier type 1");
    SoldierType1.setCharacterSize(20);
    SoldierType1.setFillColor(sf::Color::White);
    textRect = SoldierType1.getLocalBounds();
    SoldierType1.setOrigin(textRect.width/2,textRect.height/2);
    SoldierType1.setPosition((OptThree.getPosition().x), (OptThree.getPosition().y));

    SoldierType2.setFont(font);
    SoldierType2.setString("Buy soldier type 2");
    SoldierType2.setCharacterSize(20);
    SoldierType2.setFillColor(sf::Color::White);
    textRect = SoldierType2.getLocalBounds();
    SoldierType2.setOrigin(textRect.width/2,textRect.height/2);
    SoldierType2.setPosition((OptFour.getPosition().x), (OptFour.getPosition().y));
  
    TowerType1.setFont(font);
    TowerType1.setString("Buy tower type 1");
    TowerType1.setCharacterSize(20);
    TowerType1.setFillColor(sf::Color::White);
    textRect = TowerType1.getLocalBounds();
    TowerType1.setOrigin(textRect.width/2,textRect.height/2);
    TowerType1.setPosition((OptOne.getPosition().x), (OptOne.getPosition().y));

    TowerType2.setFont(font);
    TowerType2.setString("Buy tower type 2");
    TowerType2.setCharacterSize(20);
    TowerType2.setFillColor(sf::Color::White);
    textRect = TowerType2.getLocalBounds();
    TowerType2.setOrigin(textRect.width/2,textRect.height/2);
    TowerType2.setPosition((OptTwo.getPosition().x), (OptTwo.getPosition().y));

    SellTower.setFont(font);
    SellTower.setString("Sell tower");
    SellTower.setCharacterSize(20);
    SellTower.setFillColor(sf::Color::White);
    textRect = SellTower.getLocalBounds();
    SellTower.setOrigin(textRect.width/2,textRect.height/2);
    SellTower.setPosition((OptFive.getPosition().x), (OptFive.getPosition().y));
}

void StoreMenu::DrawStoreMenu(sf::RenderWindow & window)
{
    if(oneTime)
    {
	DefineTexture(window);
	oneTime = false;
    }
    //window.draw(StoreMenuSprite);
    window.draw(maphitbox1);
    window.draw(maphitbox2);
    window.draw(OptOne);
    window.draw(OptTwo);
    window.draw(OptThree);
    window.draw(OptFour);
    window.draw(OptFive);
    window.draw(OptSix);
    window.draw(SoldierType1);
    window.draw(SoldierType2);
    window.draw(TowerType1);
    window.draw(TowerType2);
    window.draw(SellTower);
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
	    option = 1;
  
	else if ( sf::Mouse::getPosition(window).x > OptTwo.getPosition().x - OptTwo.getSize().x / 2 &&
		  sf::Mouse::getPosition(window).x < OptTwo.getPosition().x + OptTwo.getSize().x / 2 &&
		  sf::Mouse::getPosition(window).y > OptTwo.getPosition().y - OptTwo.getSize().y / 2 &&
		  sf::Mouse::getPosition(window).y < OptTwo.getPosition().y + OptTwo.getSize().y / 2 )
	    option = 2;
  
	else if ( sf::Mouse::getPosition(window).x > OptThree.getPosition().x - OptThree.getSize().x / 2 &&
		  sf::Mouse::getPosition(window).x < OptThree.getPosition().x + OptThree.getSize().x / 2 &&
		  sf::Mouse::getPosition(window).y > OptThree.getPosition().y - OptThree.getSize().y / 2 &&
		  sf::Mouse::getPosition(window).y < OptThree.getPosition().y + OptThree.getSize().y / 2 )
	    option = 3;    
 
	else if ( sf::Mouse::getPosition(window).x > OptFour.getPosition().x - OptFour.getSize().x / 2 &&
		  sf::Mouse::getPosition(window).x < OptFour.getPosition().x + OptFour.getSize().x / 2 &&
		  sf::Mouse::getPosition(window).y > OptFour.getPosition().y - OptFour.getSize().y / 2 &&
		  sf::Mouse::getPosition(window).y < OptFour.getPosition().y + OptFour.getSize().y / 2 )
	    option = 4;      
	
	else  if ( sf::Mouse::getPosition(window).x > OptFive.getPosition().x - OptFive.getSize().x / 2 &&
		   sf::Mouse::getPosition(window).x < OptFive.getPosition().x + OptFive.getSize().x / 2 &&
		   sf::Mouse::getPosition(window).y > OptFive.getPosition().y - OptFive.getSize().y / 2 &&
		   sf::Mouse::getPosition(window).y < OptFive.getPosition().y + OptFive.getSize().y / 2 )
	    option = 5;	

	if (option == 1 || option == 2 || option == 3 || option == 4 || option == 5)
	{
	    if (option == 3 || option == 4)
	    {
		data = to_string(option);
		data += " 0 0";
		option = 0;
	    }
	    else if ( sf::Mouse::getPosition(window).x > maphitbox1.getPosition().x - maphitbox1.getSize().x / 2 &&
		      sf::Mouse::getPosition(window).x < maphitbox1.getPosition().x + maphitbox1.getSize().x / 2 &&
		      sf::Mouse::getPosition(window).y > maphitbox1.getPosition().y - maphitbox1.getSize().y / 2 &&
		      sf::Mouse::getPosition(window).y < maphitbox1.getPosition().y + maphitbox1.getSize().y / 2 )
	    {
		stringstream ss;
		ss << option << " ";
		ss << sf::Mouse::getPosition(window).x / 60 << " ";
		ss << sf::Mouse::getPosition(window).y / 60;
		data = ss.str();
		option = 0;
	    }
	}
    }
    return data;
}
