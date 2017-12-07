#include "ClientMenu.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>

#include "Client.h"

using namespace std;

ClientMenu::ClientMenu(sf::RenderWindow &window)
{
    font.loadFromFile("Arial.ttf");

    Header.setFont(font);
    Header.setString("");
    Header.setCharacterSize(40);
    Header.setStyle(sf::Text::Bold);
    Header.setFillColor(sf::Color::White);
    Header.setString("Join Game");
    Header.setPosition(window.getSize().x / 2,  60);
    textRect = Header.getLocalBounds();
    Header.setOrigin(textRect.left + textRect.width/2.0f,
		     textRect.top  + textRect.height/2.0f);

    Question.setFont(font);
    Question.setString("O");
    Question.setCharacterSize(30);
    Question.setStyle(sf::Text::Bold);
    Question.setFillColor(sf::Color::White);
    textRect = Question.getLocalBounds();
    heightCenter = textRect.top  + textRect.height / 2.0f;
    Question.setOrigin(textRect.left + textRect.width, heightCenter);

    Answer.setFont(font);
    Answer.setString("O");
    Answer.setCharacterSize(30);
    Answer.setStyle(sf::Text::Bold);
    Answer.setFillColor(sf::Color::White);
    textRect = Answer.getLocalBounds();
    Answer.setOrigin(textRect.left, heightCenter);
}

void ClientMenu::Boot(sf::RenderWindow &window)
{
    CustomIpAddress(window);
    Port(window);
    Connect(window);
}

void ClientMenu::CustomIpAddress(sf::RenderWindow &window)
{
    bool ifNext{false};
    
    string question = "";
    Question.setString("Ip-Address to Host: ");
    Question.setPosition(window.getSize().x / 2,  window.getSize().y / 2);
    textRect = Question.getLocalBounds();
    Question.setOrigin(textRect.left + textRect.width, heightCenter);

    string answer = "130.236.181.74";
    Answer.setString("130.236.181.74");
    Answer.setPosition(window.getSize().x / 2,  window.getSize().y / 2);

    while(window.isOpen() && !ifNext)
    {
	sf::Event event;
	while(window.pollEvent(event))
	    if (event.type == sf::Event::Closed)
		window.close();
	    else if (event.type == sf::Event::KeyPressed)
	    {
		if (event.key.code == sf::Keyboard::Escape)
		{
		    Client client(window, socket);  //remove later
		    client.RunClient();  // remove later
		    
		    window.close();
		}
		else if (event.key.code == sf::Keyboard::Return)
		    ifNext = true;
	    }
	    else if (event.type == sf::Event::TextEntered)
	    {
		if ((event.text.unicode >= 48 && event.text.unicode <= 57) || event.text.unicode == 46)
		    answer += static_cast<char>(event.text.unicode);
		else if (event.text.unicode == 8)
		    answer = answer.substr(0, answer.size() - 1);
	    }
	Answer.setString(answer);
	Draw(window);	
    }
    
    sf::IpAddress ip_temp(answer);
    ipAddress = ip_temp;
}

void ClientMenu::Port(sf::RenderWindow &window)
{
    bool ifNext{false};
    
    string question = "";
    Question.setString("Custom port? (y/n): ");
    Question.setPosition(window.getSize().x / 2,  window.getSize().y / 2);
    textRect = Question.getLocalBounds();
    Question.setOrigin(textRect.left + textRect.width, heightCenter);
    
    string answer = "";
    Answer.setString("");
    Answer.setPosition(window.getSize().x / 2,  window.getSize().y / 2);
  
    while(window.isOpen() && !ifNext)
    {
	sf::Event event;
	while(window.pollEvent(event))
	    if (event.type == sf::Event::Closed)
		window.close();
	    else if (event.type == sf::Event::KeyPressed)
	    {
		if (event.key.code == sf::Keyboard::Escape)
		    window.close();
		else if (event.key.code == sf::Keyboard::Return)
		    ifNext = true;
	    }
	    else if (event.type == sf::Event::TextEntered)
	    {
		if (event.text.unicode == 121)
		    answer = "y";
		else if (event.text.unicode == 110)
		    answer = "n";
		else if (event.text.unicode == 8)
		    answer = answer.substr(0, answer.size() - 1);
	    }
	Answer.setString(answer);
	Draw(window);	
    }

    if (answer == "y")
	CustomPort(window);
}

void ClientMenu::CustomPort(sf::RenderWindow &window)
{
    bool ifNext{false};
    
    string question = "";
    Question.setString("Custom port: ");
    Question.setPosition(window.getSize().x / 2,  window.getSize().y / 2);
    textRect = Question.getLocalBounds();
    Question.setOrigin(textRect.left + textRect.width, heightCenter);
    
    string answer = "";
    Answer.setString("");
    Answer.setPosition(window.getSize().x / 2,  window.getSize().y / 2);

    while(window.isOpen() && !ifNext)
    {
	sf::Event event;
	while(window.pollEvent(event))
	    if (event.type == sf::Event::Closed)
		window.close();
	    else if (event.type == sf::Event::KeyPressed)
	    {
		if (event.key.code == sf::Keyboard::Escape)
		    window.close();
		else if (event.key.code == sf::Keyboard::Return)
		    ifNext = true;
	    }
	    else if (event.type == sf::Event::TextEntered)
	    {
		if (event.text.unicode >= 48 && event.text.unicode <= 57)
		    answer += static_cast<char>(event.text.unicode);
		else if (event.text.unicode == 8)
		    answer = answer.substr(0, answer.size() - 1);
	    }
	Answer.setString(answer);
	Draw(window);	
    }
    
    connectionPort = stoi(answer);
}

void ClientMenu::Connect(sf::RenderWindow &window)
{
    if (window.isOpen())
    {
	bool ifNext{false};

	sf::Thread thread([&](){
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
		    Draw(window);
		}
	    });

	string temp = "Connection to IP: " + ipAddress.toString() + ":" + to_string(connectionPort);
	Question.setString(temp);
	Question.setPosition(window.getSize().x / 2,  window.getSize().y / 2);
	textRect = Question.getLocalBounds();
	Question.setOrigin(textRect.left + textRect.width/2.0f, heightCenter);
    
	Answer.setString("Waiting for Response...");
	Answer.setPosition(window.getSize().x / 2,  window.getSize().y / 2 + 50);
	textRect = Answer.getLocalBounds();
	Answer.setOrigin(textRect.left + textRect.width/2.0f, heightCenter);

	// Main window loop
	thread.launch();

	if (socket.connect(ipAddress, connectionPort, sf::seconds(30)) == sf::Socket::Done)
	{
	    //Success
	    while(true){
		sf::Packet packet;
		socket.receive(packet);
		if (packet.getDataSize() > 0){
		    ifNext = true;
		    thread.wait();
		    Client client(window, socket);
		    client.RunClient();
		    cout << "ClientMenu.cpp" << endl;
		    break;
		}
	    }
	}	
	// Timeout/Error
	ifNext = true;
	thread.wait();
    }
    // Going back to the menu!
}

void ClientMenu::Draw(sf::RenderWindow &window)
{  
    window.clear();

    window.draw(Header);
    window.draw(Question);
    window.draw(Answer);
    
    window.display();
}
