#include "Client.h" 
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include "StoreMenu.h"
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
    string sendData;
    sendData = storeMenu.StoreMenuLogic(window);
    if (soldierList.size() > 0 && towerList.size() > 0)
    {
	for (Soldier soldier : soldierList)
	    soldier.Update(deltaTime);
	for (Tower tower : towerList)
	    for (Soldier soldier : soldierList)
		tower.Update(soldier, deltaTime);
    }
}

void Client::Draw()
{
    window.clear(sf::Color(20,20,20,255));  
    storeMenu.DrawStoreMenu(window);
    window.display();
}

