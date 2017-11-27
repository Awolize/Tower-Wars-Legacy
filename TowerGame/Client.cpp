#include "Client.h" 
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include "StoreMenu.h"
#include "Ground.h"
#include <sstream>

using namespace std;

void Client::RunClient()
{
    clock.restart();
    cout << "Client.cpp" << endl;

    while(window.isOpen() && !ifNext)
    {
	userInterface();
	// Send data to server	    
	// Rec
	Update();
	Draw();
    }
}

void Client::userInterface()
{
    sf::Event event;
    while(window.pollEvent(event))
    {
	if (event.type == sf::Event::Closed)
	    window.close();
	else if (event.type == sf::Event::KeyPressed)
	{
	    if (event.key.code == sf::Keyboard::Escape)
		window.close();
	}
    }
}

void Client::Update()
{
//    Update();
  storeMenu.StoreMenuLogic(window);
  ground1.SetPosition(0, 0);
  ground2.SetPosition(680, 0);
}

void Client::Draw()
{
    window.clear(sf::Color(20,20,20,255));  
    storeMenu.DrawStoreMenu(window);
    ground1.Draw(window);
    ground2.Draw(window);
    player.DrawEconomy(window);
    window.display();
}

