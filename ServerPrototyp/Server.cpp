#include "Server.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>
using namespace std;

Server::Server()
{
}

Server::~Server()
{
}

void Server::Run()
{
    Init();
    Connect();
}

void Server::Init()
{
    char UserConnectionPort;
    char ifLAN;

    cout << "Initializing Server..." << endl;

    cout << "LAN? (y/n): ";
    cin >> ifLAN;
    if (ifLAN == 'y')
	ipAddress = sf::IpAddress::getLocalAddress();
    else
	ipAddress = sf::IpAddress::getPublicAddress();
    
    cout << "Custom port? (y/n): ";
    cin >> UserConnectionPort;
    if (UserConnectionPort == 'y')
    {
	cout << "Enter port: ";
	cin >> connectionPort;
    }
    cout << endl;

    cout << ipAddress.toString() << ":" << connectionPort << endl;
    cout << endl;
}

void Server::Connect()
{
    cout << "Establishing a connection..." << endl;
    

    if (listener.listen(connectionPort) != sf::Socket::Done)
    {
	//Error
    }
    
    
    if (listener.accept(clientSocket) != sf::Socket::Done)
    {
	//Error
    }
    cout << "Connection establishinged" << endl;


    sf::Thread thread([&]()
    {
	sf::Packet packet;
	string text;
	while(1)
	{
	    cout << "Message to client: ";
	    getline(cin, text);
	    packet << text;
	    clientSocket.send(packet);
	    packet.clear();
	}
    });
    thread.launch();

    string text;
    sf::Packet packet;

    while(1)
    {
	clientSocket.receive(packet);
	if (packet >> text)
	{
	    cout << "Message from the client: " << text << endl;
	    packet.clear();
	}
    }
}

