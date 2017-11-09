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

void Client::Boot()
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
  
}
