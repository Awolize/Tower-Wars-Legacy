#include "Client.h" 
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include "Tower.h"
#include "Soldier.h"
#include "StoreMenu.h"
#include "Ground.h"
#include <sstream>

using namespace std;

void Client::RunClient()
{
    clock.restart();
    sf::Clock deltaTimeClock;
    cout << "Client.cpp" << endl;
    ground1.SetPosition(0, 0);
    ground2.SetPosition(680, 0);

    sf::Thread thread([&]()
		      {
			  while(window.isOpen())
			  {
			      sf::Packet packet;
			      string data;
			      packet.clear();
			      socket.receive(packet);
			      if(packet.getDataSize() > 0)
			      {
				  cout << "Packet Size:" << packet.getDataSize() << endl;
		
				  stringstream ss;
				  string user = "P";
				  float coins; 
				  float income;
				  int option;
				  int x;
				  int y;
				  while (packet >> data)
				  {
				      ss << data << " ";
				  }
				  string data = ss.str();
				  ss >> coins >> income >> option >> x >> y >> user;
				  cout << ss.str() << endl;
				  cout << "Coins: " << coins << endl;
				  cout << "income: " << income << endl;
				  cout << "option: " << option << endl;
				  cout << "x, y " << x << ", " << y << endl;
				  cout << "user: " << user << endl;

				  if (user == "P2")
				  {
				      if (option == 1 || option == 2)
					  towerListP2.push_back(Tower(option, sf::Vector2i(x,y), towerIndexP2++));
				      else if (option == 3 || option == 4)
					  soldierListP2.push_back(Soldier(option, soldierIndexP2++));
				  }
				  else 
				  {
				      if (option == 1 || option == 2)
					  towerListP1.push_back(Tower(option, sf::Vector2i(x,y), towerIndexP1++));
					  
				      else if (option == 3 || option == 4)
					  soldierListP1.push_back(Soldier(option, soldierIndexP1++));
				  } 
			      }
			  }
		      });
    thread.launch(); //Om det inte ska vara en loop som håller på 24/7
    while(window.isOpen() && !ifNext)
    {
	deltaTime = deltaTimeClock.restart().asSeconds();
 	userInterface();
	SendDataToServer(strRequest());
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

string Client::strRequest()
{
    return storeMenu.StoreMenuLogic(window);
}

void Client::Update()
{
    if (soldierListP1.size() > 0 && towerListP1.size() > 0)
    {
	for (Soldier & soldier : soldierListP1)
	    soldier.Update(deltaTime);
	for (Tower & tower : towerListP1)
	    for (Soldier & soldier : soldierListP1)
		tower.Update(soldier, deltaTime);
    }
    if (soldierListP2.size() > 0 && towerListP2.size() > 0)
    {
	for (Soldier & soldier : soldierListP2)
	    soldier.Update(deltaTime);
	for (Tower & tower : towerListP2)
	    for (Soldier & soldier : soldierListP2)
		tower.Update(soldier, deltaTime);
    }
}

void Client::Draw()
{
    window.clear(sf::Color(20,20,20,255));  
    storeMenu.DrawStoreMenu(window);
    ground1.Draw(window);
    ground2.Draw(window);

    if (soldierListP1.size() > 0)
	for (Soldier & soldier : soldierListP1)
	    soldier.Draw(window);
    if (towerListP1.size() > 0)
	for (Tower & tower : towerListP1)
	    tower.Draw(window);
    if (soldierListP2.size() > 0)
	for (Soldier & soldier : soldierListP2)
	    soldier.Draw(window);
    if (towerListP2.size() > 0)
	for (Tower & tower : towerListP2)
	    tower.Draw(window);
    player.DrawEconomy(window);
    window.display();
}

void Client::SendDataToServer(string option)
{
    if (option != "")
    {
	sf::Packet packet;
	stringstream ss;
	ss << player.GetCoins() << " " << player.GetIncome() << " " << option;
	packet << ss.str();
	socket.send(packet);
    }
}
