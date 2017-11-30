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
       	
	PacketHandling(socketP1, socketP2, groundP1);
	PacketHandling(socketP2, socketP1, groundP2);
	
	sf::Time time = clock.getElapsedTime();
	cout << time.asSeconds() << endl; 

	Update();
	window.clear();
	Draw();
	window.display();
    }
}
    
void Server::PacketHandling(sf::TcpSocket &socket, sf::TcpSocket &socket2, Ground &ground)
{
    sf::Packet packet;
    string data;
    socket.receive(packet);
    if(packet.getDataSize() > 0)
    {
	cout << "Packet Size:" << packet.getDataSize() << endl;
		
	stringstream ss;
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
	ss >> coins >> income >> option >> x >> y;
	cout << "Packet data: " << ss.str() << endl;
	if (SGM.Run(coins, income, option, x, y, ground))
	{
	    socket.send(packet);
	    packet << "P2 ";
	    socket2.send(packet);
	}
    } 
}

void Server::Update()
{
}

void Server::Draw()
{

}

