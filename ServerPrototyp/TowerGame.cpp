#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>

#include "TowerGame.h" 

using namespace std;

void TowerGame::RunGame()
{
    clock.restart();

    cout << "TowerGame.cpp" << endl;
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
	
	socket.receive(packet);
	packet >> deltaTime;

	sf::Time time = clock.getElapsedTime();
	cout << time.asSeconds() << endl;

//	deltaTime = clock.restart().asSeconds();
	if (deltaTime > 1.0f / 60.0f)
	    deltaTime = 1.0f / 60.0f;
	
	Update();
	window.clear();
	Draw();
	window.display();

    }
}

void TowerGame::Update()
{
}

void TowerGame::Draw()
{
}