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

void Client::Boot(sf::RenderWindow &window)
{
    Init(window);
    Connect(window);
}

void Client::Init(sf::RenderWindow &window)
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

  sf::RectangleShape IpAddressTextBox;
    IpAddressTextBox.setSize(sf::Vector2f(400, 100)); // fix position, size, texture, text
    IpAddressTextBox.setPosition(sf::Vector2f(window.getSize().x / 2,  window.getSize().y / 2));
    IpAddressTextBox.setOrigin(sf::Vector2f(IpAddressTextBox.getSize() / 2.0f));
//    IpAddressTextBox.setColor();
    sf::Font font;
    font.loadFromFile("Arial.ttf");
    sf::Text IpAddressText;
    IpAddressText.setFont(font);
    IpAddressText.setString("Enter Ip-Address, Finish with Enter");
    IpAddressText.setCharacterSize(30);
    IpAddressText.setStyle(sf::Text::Bold);
    IpAddressText.setFillColor(sf::Color::White);
    IpAddressText.setPosition(500,500);

    string ipAddress;

    while(window.isOpen())
    {
	sf::Event event;
	while(window.pollEvent(event))
	{
	    if (event.type == sf::Event::TextEntered)
	    {
		if (event.text.unicode >= 48 && event.text.unicode <= 58)
		    ipAddress += static_cast<char>(event.text.unicode);
		else if (event.text.unicode == 8)
		    ipAddress = ipAddress.substr(0, ipAddress.size() - 1);
		IpAddressText.setString(ipAddress);
	    }
	    
	}
	window.clear();
	
        //Update(); animation?
	
	cout << ipAddress << endl;

	//Draw
	window.draw(IpAddressText);

  	window.display();
	
    }
}

void Client::Connect(sf::RenderWindow &window)
{
    std::cout << "Establishing a connection..." << std::endl;

    status = socket.connect(ipAddress, connectionPort);
    if (status != sf::Socket::Done)
    {
	// error
    }
    cout << "Connection establishinged" << endl;
  
}
