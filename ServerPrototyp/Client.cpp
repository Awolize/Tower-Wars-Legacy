#include "Client.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>

using namespace std;

Client::Client()
{
}

Client::~Client()
{
}

void Client::Run()
{
    Init();
    Connect();
}

void Client::Init()
{
    char UserConnectionPort;
    string getIpAddress;

    cout << "Initializing Server..." << endl;
    cout << "Ip Address: ";
    cin >> getIpAddress;
    ipAddress =	sf::IpAddress(getIpAddress);

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

void Client::Connect()
{
    std::cout << "Establishing a connection..." << std::endl;
    status = socket.connect(ipAddress, connectionPort);
    if (status != sf::Socket::Done)
    {
	// error
    }
    cout << "Connection establishinged" << endl;
    

    sf::Thread thread([&]()
    {
	sf::Packet packet;
	string text;
	while(1)
	{
	    cout << "Message to server: ";
	    getline(cin, text);
	    packet << text;
	    socket.send(packet);
	    packet.clear();
	}
    });
    thread.launch();

    string text;
    sf::Packet packet;

    while(1)
    {
	socket.receive(packet);
	if (packet >> text)
	{
	    cout << "Message from the server: " << text << endl;
	    packet.clear();
	}
    }

}
