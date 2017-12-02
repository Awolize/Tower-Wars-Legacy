#include "ServerMenu.h"
#include "ClientMenu.h"
#include "MainMenu.h"

#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;


MainMenu::MainMenu() {}

MainMenu::~MainMenu() {}

void MainMenu::DefineTexture(sf::RenderWindow &window)
{
    font.loadFromFile("Arial.ttf");

    HostGameText.setFont(font);
    HostGameText.setCharacterSize(30);
    HostGameText.setFillColor(sf::Color::White);
    HostGameText.setString("Host Game");
    HostGameText.setPosition(sf::Vector2f(window.getSize().x / 2,  window.getSize().y / 2 - 150));

    textRect = HostGameText.getLocalBounds();
    HostGameText.setOrigin(textRect.left + textRect.width/2.0f,
			   textRect.top  + textRect.height/2.0f);
    
    JoinGameText.setFont(font);
    JoinGameText.setCharacterSize(30);
    JoinGameText.setFillColor(sf::Color::White);
    JoinGameText.setString("Join Game");
    JoinGameText.setPosition(sf::Vector2f(window.getSize().x / 2,  window.getSize().y / 2));
    textRect = JoinGameText.getLocalBounds();
    JoinGameText.setOrigin(textRect.left + textRect.width/2.0f,
			   textRect.top  + textRect.height/2.0f);
   
    QuitGameText.setFont(font);
    QuitGameText.setCharacterSize(30);
    QuitGameText.setFillColor(sf::Color::White);
    QuitGameText.setString("Quit Game");
    QuitGameText.setPosition(sf::Vector2f(window.getSize().x / 2,  window.getSize().y / 2 + 150));
    textRect = QuitGameText.getLocalBounds();
    QuitGameText.setOrigin(textRect.left + textRect.width/2.0f,
			   textRect.top  + textRect.height/2.0f);
   
    HostMenuOption.setSize(sf::Vector2f(400, 100)); // fix position, size, texture, text
    HostMenuOption.setPosition(sf::Vector2f(window.getSize().x / 2,  window.getSize().y / 2 - 150));
    HostMenuOption.setOrigin(sf::Vector2f(HostMenuOption.getSize() / 2.0f));
    HostMenuOption.setFillColor(sf::Color(20, 20, 20));

// Join Server menuoption ractangle
    JoinMenuOption.setSize(sf::Vector2f(400, 100)); // fix position, size, texture, text
    JoinMenuOption.setPosition(sf::Vector2f(window.getSize().x / 2,  window.getSize().y / 2));
    JoinMenuOption.setOrigin(sf::Vector2f(JoinMenuOption.getSize() / 2.0f));
    JoinMenuOption.setFillColor(sf::Color(20, 20, 20));

// Close game menuoption ractangle
    QuitMenuOption.setSize(sf::Vector2f(400, 100)); // fix position, size, texture, text
    QuitMenuOption.setPosition(sf::Vector2f(window.getSize().x / 2,  window.getSize().y / 2 + 150));
    QuitMenuOption.setOrigin(sf::Vector2f(QuitMenuOption.getSize() / 2.0f));
    QuitMenuOption.setFillColor(sf::Color(20, 20, 20));

}

void MainMenu::Run(sf::RenderWindow &window)
{
    DefineTexture(window);
    while(window.isOpen())
    {
	CheckButtons(window);
	Update(window);
	Draw(window);
    }
}

void MainMenu::CheckButtons(sf::RenderWindow &window)
{
    sf::Event event;
    while(window.pollEvent(event))
    {
	if (event.type == event.Closed)
	    window.close();    
	else if (event.type == sf::Event::KeyPressed)
	{
	    if (event.key.code == sf::Keyboard::Escape)
		window.close();
	}  
	// HostMenuOption
	else if (   event.mouseButton.x > HostMenuOption.getPosition().x - HostMenuOption.getSize().x / 2 && 
		    event.mouseButton.x < HostMenuOption.getPosition().x + HostMenuOption.getSize().x / 2 && 
		    event.mouseButton.y > HostMenuOption.getPosition().y - HostMenuOption.getSize().y / 2 && 
		    event.mouseButton.y < HostMenuOption.getPosition().y + HostMenuOption.getSize().y / 2 )
	{		
	    if (event.mouseButton.button == sf::Mouse::Left)
	    {
		ServerMenu serverMenu(window);
		serverMenu.Boot(window);
	    }
	}		
	// JoinMenuOption
	else if (   event.mouseButton.x > JoinMenuOption.getPosition().x - JoinMenuOption.getSize().x / 2 && 
		    event.mouseButton.x < JoinMenuOption.getPosition().x + JoinMenuOption.getSize().x / 2 && 
		    event.mouseButton.y > JoinMenuOption.getPosition().y - JoinMenuOption.getSize().y / 2 && 
		    event.mouseButton.y < JoinMenuOption.getPosition().y + JoinMenuOption.getSize().y / 2 )
	{
	    if (event.mouseButton.button == sf::Mouse::Left)
	    {
		ClientMenu clientMenu(window);
		clientMenu.Boot(window);
	    }
	}
	// QuitMenuOption
	else if (   event.mouseButton.x > QuitMenuOption.getPosition().x - QuitMenuOption.getSize().x / 2 && 
		    event.mouseButton.x < QuitMenuOption.getPosition().x + QuitMenuOption.getSize().x / 2 && 
		    event.mouseButton.y > QuitMenuOption.getPosition().y - QuitMenuOption.getSize().y / 2 && 
		    event.mouseButton.y < QuitMenuOption.getPosition().y + QuitMenuOption.getSize().y / 2 )
	{	
	    if (event.mouseButton.button == sf::Mouse::Left)
	    {        
		window.close();
	    }
	}
    }
}

void MainMenu::Update(sf::RenderWindow & window)
{
    HostGameText.setFillColor(sf::Color::White);
    JoinGameText.setFillColor(sf::Color::White);
    QuitGameText.setFillColor(sf::Color::White);

    //  Animation hover
    if (   sf::Mouse::getPosition(window).x > HostMenuOption.getPosition().x - HostMenuOption.getSize().x / 2 &&
	   sf::Mouse::getPosition(window).x < HostMenuOption.getPosition().x + HostMenuOption.getSize().x / 2 &&
	   sf::Mouse::getPosition(window).y > HostMenuOption.getPosition().y - HostMenuOption.getSize().y / 2 &&
	   sf::Mouse::getPosition(window).y < HostMenuOption.getPosition().y + HostMenuOption.getSize().y / 2 )
    {
	HostGameText.setFillColor(sf::Color::Red);
    }

    else if (   sf::Mouse::getPosition(window).x > JoinMenuOption.getPosition().x - JoinMenuOption.getSize().x / 2 && 
		sf::Mouse::getPosition(window).x < JoinMenuOption.getPosition().x + JoinMenuOption.getSize().x / 2 && 
		sf::Mouse::getPosition(window).y > JoinMenuOption.getPosition().y - JoinMenuOption.getSize().y / 2 && 
		sf::Mouse::getPosition(window).y < JoinMenuOption.getPosition().y + JoinMenuOption.getSize().y / 2 )
    {
	JoinGameText.setFillColor(sf::Color::Red);
    }

    else if (   sf::Mouse::getPosition(window).x > QuitMenuOption.getPosition().x - QuitMenuOption.getSize().x / 2 && 
		sf::Mouse::getPosition(window).x < QuitMenuOption.getPosition().x + QuitMenuOption.getSize().x / 2 && 
		sf::Mouse::getPosition(window).y > QuitMenuOption.getPosition().y - QuitMenuOption.getSize().y / 2 && 
		sf::Mouse::getPosition(window).y < QuitMenuOption.getPosition().y + QuitMenuOption.getSize().y / 2 )
    {	
	QuitGameText.setFillColor(sf::Color::Red);
    }
}

void MainMenu::Draw(sf::RenderWindow & window)
{
    window.clear();

    window.draw(HostMenuOption);
    window.draw(JoinMenuOption);
    window.draw(QuitMenuOption);

    window.draw(HostGameText);
    window.draw(JoinGameText);
    window.draw(QuitGameText);

    window.display();
}
