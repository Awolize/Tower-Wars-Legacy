#include "Client.h" 
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>

using namespace std;

void Client::RunClient()
{
    clock.restart();

    cout << "Client.cpp" << endl;
    bool ifNext = false;
    sf::Packet packet;

    // Background
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
	    // User controlls, UI
	}
	// send data to server
	packet.clear();
//	packet << type << coord;
	socket.send(packet);

        // Thread, receive data from server
	packet.clear();
//	packet >> type >> coord;
	// string type = "m1";
	// string type = "t1";
	socket.receive(packet);

	// update
	Update();

	// Draw
	Draw();

	// repeat
    }
}

void Client::Update()
{
}

void Client::Draw()
{
    window.clear();  

    window.display();
}

