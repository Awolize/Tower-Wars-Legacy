#include "Client.h" 
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include "Tower.h"
#include "Soldier.h"
#include "StoreMenu.h"
#include "Ground.h"
#include "Player.h"
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
			      socket.receive(packet);
			      if (packet.getDataSize() > 0 && packet.getDataSize() < 10) {thread.wait();}
			      else if(packet.getDataSize() > 0)
			      {
				  cout << "Packet Size:" << packet.getDataSize() << endl;
		
				  stringstream ss;
				  int user = 1;
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
				  cout << "x, y: (" << x << ", " << y << ")" << endl;
				  cout << "user: " << user << endl;

				  if (user == 2)
				  {
				      if (option == 1 || option == 2)
					  towerListP2.push_back(Tower(option, sf::Vector2i(x,y), 2));
				      else if (option == 3 || option == 4)
					  soldierListP1.push_back(Soldier(option, 1, player));
				      else if (option == 5)
				      {
					  for (auto it = towerListP2.begin(); it != towerListP2.end(); ++it)
					      if (sf::Vector2i(x,y) == it->getPos())
					      {
						  towerListP2.erase(it);
						  break;
					      }
				      }

				  }
				  else 
				  {
				      if (option == 1 || option == 2)
				      {
					  towerListP1.push_back(Tower(option, sf::Vector2i(x,y), 1));
					  player.BuyWithCoins(Tower(option).getCost(), 0);
				      }	  
				      else if (option == 3 || option == 4)
				      {
					  soldierListP2.push_back(Soldier(option, 2, player));
					  player.BuyWithCoins(Soldier(option).getCost(), Soldier(option).getIncome());
				      }
				      else if (option == 5)
				      {
					  for (auto it = towerListP1.begin(); it != towerListP1.end(); ++it)
					      if (sf::Vector2i(x,y) == it->getPos())
					      {
						  towerListP1.erase(it);
						  player.BuyWithCoins(-10, 0);	
						  break;
					      }
				      }

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
    if (!window.isOpen())
    {
	sf::Packet packet;
	string done = "Done!";
	packet << done;
	socket.send(packet);
    
	cout << "thread.wait()" << endl;
	thread.wait();
	float endScreenTimer = clock.getElapsedTime().asSeconds() + 7;
    
	cout << endScreenTimer << " > ";
	cout << clock.getElapsedTime().asSeconds() << endl;

	while (endScreenTimer > clock.getElapsedTime().asSeconds())
	{
	    userInterface();
	    Draw();
	}
	if (player.getWinner() == 1)
	    cout << "Winner: Player 1" << endl;
	else if (player.getWinner() == 2)
	    cout << "Winner: Player 2" << endl;
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
	    else if (event.key.code == sf::Keyboard::Num1)
		soldierListP1.push_back(Soldier(3, 1, player));
	    else if (event.key.code == sf::Keyboard::Num2)
		soldierListP1.push_back(Soldier(4, 1, player));
	    else if (event.key.code == sf::Keyboard::Num3)
		towerListP1.push_back(Tower(1, sf::Vector2i(5,5), 1));
	    else if (event.key.code == sf::Keyboard::Num4)
		towerListP1.push_back(Tower(2, sf::Vector2i(3,3), 1));
	}
    }
}

string Client::strRequest()
{
    return storeMenu.StoreMenuLogic(window);
}

// Remove index för allt, använder pointers istället

void Client::Update()
{
    if (player.GameOver())
	ifNext = true;

    if (soldierListP1.size() > 0)
	for (Soldier & soldier : soldierListP1)
	    soldier.Update(deltaTime);
	
    if (towerListP1.size() > 0)
	for (Tower & tower : towerListP1)
	{
	    if (soldierListP1.size() > 0)
		if (!tower.gotTarget())	
		    for (Soldier & soldier : soldierListP1)
			tower.getTarget(soldier);	 
	    tower.Update(deltaTime);
	}

    if (soldierListP2.size() > 0)
	for (Soldier & soldier : soldierListP2)
	    soldier.Update(deltaTime);

    if (towerListP2.size() > 0)
	for (Tower & tower : towerListP2)
	{
	    if (soldierListP2.size() > 0)
		if (!tower.gotTarget())
		    for (Soldier & soldier : soldierListP2)
			tower.getTarget(soldier);
	    tower.Update(deltaTime);
	}
    player.Update();
}

void Client::Draw()
{
    window.clear(sf::Color(0,0,0,255));  
    storeMenu.Draw(window);
    ground1.Draw(window);
    ground2.Draw(window);
    player.Draw(window);

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
    window.display();
}

void Client::SendDataToServer(string option)
{
    if (option != "")
    {
	sf::Packet packet;
	stringstream ss;
	ss << player.getCoins() << " " << player.getIncome() << " " << option;
	packet << ss.str();
	socket.send(packet);
    }
}
