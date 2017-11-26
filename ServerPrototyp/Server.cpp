#include "Server.h" 
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>

using namespace std;

void Server::RunServer()
{
    clock.restart();

    cout << "Server.cpp" << endl;
    bool ifNext = false;
    sf::Packet packet;


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
	
	
	

	
//	deltaTime = clock.restart().asSeconds();
	if (deltaTime > 1.0f / 60.0f)
	    deltaTime = 1.0f / 60.0f;
	packet << deltaTime;
//	cout << deltaTime << endl;
//	socketP1.send(packet);
//	socketP2.send(packet);

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

