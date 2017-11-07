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
    cout << endl;
    cout << "Custom port? (y/n): ";
    cin >> UserConnectionPort;
    cout << endl;
    if (UserConnectionPort == 'y')
    {
	cout << "Enter port: ";
	cin >> connectionPort;
	cout << endl;
    }
}

void Client::Connect()
{
    std::cout << "___Connect____" << std::endl;
}
