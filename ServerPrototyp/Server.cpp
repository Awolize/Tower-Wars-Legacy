#include "Server.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>
using namespace std;

Server::Server(sf::RenderWindow &window)
{
    IpAddressTextBox.setSize(sf::Vector2f(400, 100)); // fix position, size, texture, text
    IpAddressTextBox.setPosition(sf::Vector2f(window.getSize().x / 2,  window.getSize().y / 2));
    IpAddressTextBox.setOrigin(sf::Vector2f(IpAddressTextBox.getSize() / 2.0f));

    font.loadFromFile("Arial.ttf");

    Question.setFont(font);
    Question.setString("");
    Question.setCharacterSize(30);
    Question.setStyle(sf::Text::Bold);
    Question.setFillColor(sf::Color::White);

    Answer.setFont(font);
    Answer.setString("");
    Answer.setCharacterSize(30);
    Answer.setStyle(sf::Text::Bold);
    Answer.setFillColor(sf::Color::White);
}

Server::~Server()
{
}

void Server::Boot(sf::RenderWindow &window)
{
    Lan(window); 
    Port(window);
    Connect(window);
}

void Server::Lan(sf::RenderWindow &window)
{
    bool ifNext{false};
    
    string question = "";
    Question.setString("Lan? (y/n): ");
    Question.setPosition(window.getSize().x / 2 - 160,  window.getSize().y / 2);
    
    
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
		    answer = answer.substr(0, strPort.size() - 1);
	    }
	Answer.setString(answer);
	window.clear();

	window.draw(Question);
	window.draw(Answer);

  	window.display();
	
    }

    if (answer == "y")
	ipAddress = sf::IpAddress::getLocalAddress();
    else
	ipAddress = sf::IpAddress::getPublicAddress();
}

void Server::Port(sf::RenderWindow &window)
{
    bool ifNext{false};
    
    string question = "";
    Question.setString("Custom port? (y/n): ");
    Question.setPosition(window.getSize().x / 2 - 200,  window.getSize().y / 2);
    
    
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
		    answer = answer.substr(0, strPort.size() - 1);
	    }
	Answer.setString(answer);
	window.clear();

	window.draw(Question);
	window.draw(Answer);

  	window.display();
	
    }

    if (answer == "y")
	CustomPort(window);
}

void Server::CustomPort(sf::RenderWindow &window)
{
    bool ifNext{false};
    
    string question = "";
//    sf::Text Question;
    Question.setFont(font);
    Question.setString("Custom port? (y/n): ");
    Question.setCharacterSize(30);
    Question.setStyle(sf::Text::Bold);
    Question.setFillColor(sf::Color::White);
    Question.setPosition(window.getSize().x / 2 - 200,  window.getSize().y / 2);
    
    
    string answer = "";
//    sf::Text Answer;
    Answer.setFont(font);
    Answer.setString("");
    Answer.setCharacterSize(30);
    Answer.setStyle(sf::Text::Bold);
    Answer.setFillColor(sf::Color::White);
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
		    answer = answer.substr(0, strPort.size() - 1);
	    }
	Answer.setString(answer);
	window.clear();

	window.draw(Question);
	window.draw(Answer);

  	window.display();
	
    }

    connectionPort = stoi(answer);
}

void Server::Draw(sf::RenderWindow &window)
{
    /*
      if (event.text.unicode >= 48 && event.text.unicode <= 57)
      {
      strPort += static_cast<char>(event.text.unicode);
      ConstStrPort += static_cast<char>(event.text.unicode);
      }
      else if (event.text.unicode == 8)
      {
      strPort = strPort.substr(0, strPort.size() - 1);
      ConstStrPort = ConstStrPort.substr(0, ConstStrPort.size() - 1);
      }

      }
    */	    
}

void Server::Connect(sf::RenderWindow &window)
{
    cout << "Your IP: " << ipAddress << ":" << strPort << endl;


    while(window.isOpen())
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
	window.clear();
	
        // Update(); animation?

        // Draw
//	window.draw(Continue);

  	window.display();

	cout << "hej1" << endl;
	if (listener.listen(connectionPort) != sf::Socket::Done)
	{
	    //Error
	}
	cout << "hej2" << endl;
    
	if (listener.accept(clientSocket) == sf::Socket::Done)
	{
	    //Success
	    cout << "New connection received from: " << clientSocket.getRemoteAddress() << endl;
	    // jumpToNextStage(clientSocket);
	}
	cout << "hej3" << endl;
	
    }	
}
