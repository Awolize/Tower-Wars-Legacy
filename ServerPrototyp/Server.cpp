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

    cout << "Ip Address: " << ipAddress.toString() << endl;
    cout << "      Port: " << connectionPort << endl;
    cout << endl;
}

void Server::Connect()
{
    std::cout << "Connect" << std::endl;
}
