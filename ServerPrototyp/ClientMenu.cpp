#include "ClientMenu.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>

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
    Header.setPosition(window.getSize().x / 2 - 100,  60);

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

void ClientMenu::Boot(sf::RenderWindow &window)
{
    Port(window);
    CustomIpAddress(window);
    Connect(window);
}

void ClientMenu::Port(sf::RenderWindow &window)
{
    bool ifNext{false};
    
    string question = "";
    Question.setString("Custom port? (y/n): ");
    Question.setPosition(window.getSize().x / 2 - 300,  window.getSize().y / 2 - Question.getCharacterSize() / 2);
    
    string answer = "";
    Answer.setString("");
    Answer.setPosition(window.getSize().x / 2,  window.getSize().y / 2 - Answer.getCharacterSize() / 2);


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
    Question.setPosition(window.getSize().x / 2 - 200,  window.getSize().y / 2 - Question.getCharacterSize() / 2);
    
    string answer = "";
    Answer.setString("");
    Answer.setPosition(window.getSize().x / 2,  window.getSize().y / 2 - Answer.getCharacterSize() / 2);

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

void ClientMenu::CustomIpAddress(sf::RenderWindow &window)
{
    bool ifNext{false};
    
    string question = "";
    Question.setString("Ip-Address to Host: ");
    Question.setPosition(window.getSize().x / 2 - 300,  window.getSize().y / 2 - Question.getCharacterSize() / 2);
    
    string answer = "";
    Answer.setString("");
    Answer.setPosition(window.getSize().x / 2,  window.getSize().y / 2 - Answer.getCharacterSize() / 2);

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
		if (event.text.unicode >= 48 && event.text.unicode <= 57 || event.text.unicode == 46)
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

void ClientMenu::Connect(sf::RenderWindow &window)
{
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
      	Draw(window);
	sf::Thread thread([&](){
		if (socket.connect(ipAddress, connectionPort) == sf::Socket::Done)
		{
		    //Success
		    // jumpToNextStage(window, socket);
		    cout << "WoRkS!!" << endl;
		}
		thread.wait();
	    });
	thread.launch();
    }	
}

void ClientMenu::Draw(sf::RenderWindow &window)
{  
    window.clear();
    window.draw(Header);
    window.draw(Question);
    window.draw(Answer);
    window.display();
}
