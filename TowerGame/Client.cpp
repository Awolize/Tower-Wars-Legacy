#include "Client.h" 
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>

#include <sstream>

using namespace std;

void Client::RunClient()
{
    clock.restart();

    cout << "Client.cpp" << endl;
    bool ifNext = false;

    // type: 0 = tower, 1 = minion, 2 = remove tower, 3 = remove soldier 
    // tier: 0 = 0 tower/minion, 1 = tier 1 tower/minion
    // coord: x
    // coord: y
    // index: int
    // bool: 1/0, y/n, true/false
    
    // Background
    while(window.isOpen() && !ifNext)
    {
	sendData = "";
	// Standard User Controlls, UI
	userInterface();
	// send data to server	    
	if (sendData != "") {
	    sendPacket.clear();
	    sendPacket << sendData;
	    socket.send(sendPacket);
	}

/*        // Thread, receive data from server
	{
	    recPacket.clear();
	    socket.receive(recPacket);
	    recData.clear();
	    recPacket >> recData;
	    if (recData.at(0) == 0)
	    {
		SpawnTower(recData);
	    }
	    else if (recData.at(0) == 1)
	    {
		SpawnMinion(recData);
	    }
	    else if (recData.at(0) == 2)
	    {
		RemoveTower(recData);
	    }
	    else if (recData.at(0) == 3)
	    {
		RemoveMinion(recData);
	    }
	}
*/
	// Update
	Update();

	// Draw
	Draw();

	// repeat
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
	//else if ()
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

