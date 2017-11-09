#include "TowerGame.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;


// #include "Server.h"
// #include "Client.h"

TowerGame::TowerGame()
{
}

TowerGame::~TowerGame()
{
}

void TowerGame::MainMenu(sf::RenderWindow &window)
{
    sf::RectangleShape menuChoiceHostServer(sf::Vector2f(400.0f, 100.0f));
    menuChoiceHostServer.setFillColor(sf::Color::Red);
    menuChoiceHostServer.setPosition(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2 - 150));
    menuChoiceHostServer.setOrigin(menuChoiceHostServer.getSize() / 2.0f);

    sf::RectangleShape menuChoiceJoinServer(sf::Vector2f(400.0f, 100.0f));
    menuChoiceJoinServer.setFillColor(sf::Color::Green);
    menuChoiceJoinServer.setPosition(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2 ));
    menuChoiceJoinServer.setOrigin(menuChoiceJoinServer.getSize() / 2.0f);

    sf::RectangleShape menuChoiceQuitGame(sf::Vector2f(400.0f, 100.0f));
    menuChoiceQuitGame.setFillColor(sf::Color::Blue);
    menuChoiceQuitGame.setPosition(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2 + 150));
    menuChoiceQuitGame.setOrigin(menuChoiceQuitGame.getSize() / 2.0f);
/*
  if(menuOption == 1)
  {
  Server server;
  server.Boot();
  }
  else if(menuOption == 2)
  {
  Client client;
  client.Boot();
  }
*/
	window.draw(menuChoiceHostServer);
	window.draw(menuChoiceJoinServer);
	window.draw(menuChoiceQuitGame);

}

void TowerGame::Run()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "TowerGame", 
			    sf::Style::Close | sf::Style::Resize);

    while(window.isOpen())
    {
	sf::Event event;
	while(window.pollEvent(event))
	{
	    if (event.type == event.Closed)
		window.close();
	}

	window.clear();

	MainMenu(window);
	
	//Update(Window);
	//Draw(window);

	window.display();
	
    }
}
