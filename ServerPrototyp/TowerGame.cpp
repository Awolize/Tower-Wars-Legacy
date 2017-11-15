#include "TowerGame.h"
#include "Server.h"
#include "Client.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;




TowerGame::TowerGame()
{
}

TowerGame::~TowerGame()
{
}

void TowerGame::MainMenu(sf::RenderWindow &window)
{
    cout << "Menu Option (1/2/3): ";
    cin >> menuOption;
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
    else if(menuOption == 3)
    {
	cout << "Closing the game..." << endl;
	window.close();
    }
}

void TowerGame::Run()
{
    sf::RenderWindow window(sf::VideoMode(1280, 1024), "TowerGame", 
			    sf::Style::Close);

    while(window.isOpen())
    {
	sf::Event event;
	while(window.pollEvent(event))
	{
	    if (event.type == event.Closed)
		window.close();
	}
	
	if (menuOption == 0)
	{
	    MainMenu(window);
	}
	else if(menuOption == 1)
	{

	}
	else if(menuOption == 2)
	{
	    // Clientmenu
	}
	else if(menuOption == 3)
	{
	    cout << "Closing the game..." << endl;
	    window.close();
	    
	}

	window.clear();
	
	//Update(Window);
	//Draw(window);
	
	window.display();
	
    }
}
