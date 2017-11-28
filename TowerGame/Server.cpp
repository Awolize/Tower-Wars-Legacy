#include "Server.h" 
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <sstream>

using namespace std;

void Server::RunServer()
{
    clock.restart();

    cout << "Server.cpp" << endl;
    bool ifNext = false;

    while(window.isOpen() && !ifNext)
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
	
	socketP1.receive(packetP1);
	socketP2.receive(packetP2);
	cout << packetP1.getDataSize() << endl;
	{
	    string data;
	    if(packetP1.getDataSize() > 0)
	    {
		stringstream ss;
		float coins; 
		float income;
		int option;
		int x;
		int y;
		while (packetP1 >> data)
		{
		    ss << data << " ";
		}
		string data = ss.str();
		ss >> coins >> income >> option >> x >> y;
		cout << ss.str() << endl;
	    } 
	}
/*	if(recPacketP2 >> x >> y >> z >> w)
	{

	} */

	sf::Time time = clock.getElapsedTime();
	cout << time.asSeconds() << endl; 

	Update();
	window.clear();
	Draw();
	window.display();

    }
}

void Server::Update()
{
}

void Server::Draw()
{
}

