#include "Server.h"
#include "Client.h"
#include "MainMenu.h"

#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;


MainMenu::MainMenu() {}

MainMenu::~MainMenu() {}

void MainMenu::Run(sf::RenderWindow &window)
{
//    sf::Font font;
//    font.loadFromFile("arial.ttf");
// Host Server menuoption ractangle
    sf::RectangleShape HostMenuOption;
    HostMenuOption.setSize(sf::Vector2f(400, 100)); // fix position, size, texture, text
    HostMenuOption.setPosition(sf::Vector2f(window.getSize().x / 2, 
					    window.getSize().y / 2 - 150));
    HostMenuOption.setOrigin(sf::Vector2f(HostMenuOption.getSize() / 2.0f));
// Host Server menuoption Text
//    sf::Text text("Host Game", font);
//    text.setCharacterSize(30);
//    text.setStyle(sf::Text::Bold);
//    text.setColor(sf::Color::Red);

// Join Server menuoption ractangle
    sf::RectangleShape JoinMenuOption;
    JoinMenuOption.setSize(sf::Vector2f(400, 100)); // fix position, size, texture, text
    JoinMenuOption.setPosition(sf::Vector2f(window.getSize().x / 2,  window.getSize().y / 2));
    JoinMenuOption.setOrigin(sf::Vector2f(JoinMenuOption.getSize() / 2.0f));
// Join Server menuoption Text
//    sf::Text text("Join Game", font);
//    text.setCharacterSize(30);
//    text.setStyle(sf::Text::Bold);
//    text.setColor(sf::Color::Red);

// Close game menuoption ractangle
    sf::RectangleShape QuitMenuOption;
    QuitMenuOption.setSize(sf::Vector2f(400, 100)); // fix position, size, texture, text
    QuitMenuOption.setPosition(sf::Vector2f(window.getSize().x / 2, 
					    window.getSize().y / 2 + 150));
    QuitMenuOption.setOrigin(sf::Vector2f(QuitMenuOption.getSize() / 2.0f));
// Close Server menuoption Text
//    sf::Text text("Close", font);
//    text.setCharacterSize(30);
//    text.setStyle(sf::Text::Bold);
//    text.setColor(sf::Color::Red);

    while(window.isOpen())
    {
	sf::Event event;
	while(window.pollEvent(event))
	{
	    if (event.type == event.Closed)
		window.close();      
	    // HostMenuOption
	    if (   event.mouseButton.x > HostMenuOption.getPosition().x - HostMenuOption.getSize().x / 2 
		   && event.mouseButton.x < HostMenuOption.getPosition().x + HostMenuOption.getSize().x / 2
		   && event.mouseButton.y > HostMenuOption.getPosition().y - HostMenuOption.getSize().x / 2
		   && event.mouseButton.y < HostMenuOption.getPosition().y + HostMenuOption.getSize().y / 2 )
	    {
		if (event.mouseButton.button == sf::Mouse::Left)
		{
		    Server server(window);
		    server.Boot(window);
		}
		// Change color on text when hover?
	    }		
	    // JoinMenuOption
	    if (   event.mouseButton.x > JoinMenuOption.getPosition().x - JoinMenuOption.getSize().x / 2 
		   && event.mouseButton.x < JoinMenuOption.getPosition().x + JoinMenuOption.getSize().x / 2 
		   && event.mouseButton.y > JoinMenuOption.getPosition().y - JoinMenuOption.getSize().y / 2 
		   && event.mouseButton.y < JoinMenuOption.getPosition().y + JoinMenuOption.getSize().y / 2 )
	    {
		if (event.mouseButton.button == sf::Mouse::Left)
		{
		    Client client;
		    client.Boot(window);
		}
		// Change color on text when hover?
	    }
	    // QuitMenuOption
	    if (   event.mouseButton.x > QuitMenuOption.getPosition().x - QuitMenuOption.getSize().x / 2 
		   && event.mouseButton.x < QuitMenuOption.getPosition().x + QuitMenuOption.getSize().x / 2  
		   && event.mouseButton.y > QuitMenuOption.getPosition().y - QuitMenuOption.getSize().y / 2 
		   && event.mouseButton.y < QuitMenuOption.getPosition().y + QuitMenuOption.getSize().y / 2 )
	    {	
		if (event.mouseButton.button == sf::Mouse::Left)
		{        
		    window.close();
		}
		// Change color on text when hover?
	    }
	}
	window.clear();
	
        //Update(); animation?
	
	//Draw
	window.draw(HostMenuOption);
	window.draw(JoinMenuOption);
	window.draw(QuitMenuOption);

  	window.display();
	
    }
}
