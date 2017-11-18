#include "ServerMenu.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>
using namespace std;

ServerMenu::ServerMenu(sf::RenderWindow &window)
{
    font.loadFromFile("Arial.ttf");

    Header.setFont(font);
    Header.setString("");
    Header.setCharacterSize(40);
    Header.setStyle(sf::Text::Bold);
    Header.setFillColor(sf::Color::White);
    Header.setString("Host Game");
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

void ServerMenu::Boot(sf::RenderWindow &window)
{
    Lan(window); 
    Port(window);
    Connect(window);
}

void ServerMenu::Lan(sf::RenderWindow &window)
{
    bool ifNext{false};
    
    string question = "";
    Question.setString("Lan? (y/n): ");
    Question.setPosition(window.getSize().x / 2,  window.getSize().y / 2);
    textRect = Question.getLocalBounds();
    Question.setOrigin(textRect.left + textRect.width, heightCenter);
    
    
    string answer = "";
    Answer.setString("");
    Answer.setPosition(window.getSize().x / 2, window.getSize().y / 2);

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
	ipAddress = sf::IpAddress::getLocalAddress();
    else
	ipAddress = sf::IpAddress::getPublicAddress();
}

void ServerMenu::Port(sf::RenderWindow &window)
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

void ServerMenu::CustomPort(sf::RenderWindow &window)
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

void ServerMenu::Connect(sf::RenderWindow &window)
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

    string temp = "Your IP: " + ipAddress.toString() + ":" + to_string(connectionPort);
    Question.setString(temp);
    Question.setPosition(window.getSize().x / 2,  window.getSize().y / 2);
    textRect = Question.getLocalBounds();
    Question.setOrigin(textRect.left + textRect.width/2.0f, heightCenter);
    
    Answer.setString("Waiting for Player...");
    Answer.setPosition(window.getSize().x / 2,  window.getSize().y / 2 + 50);
    textRect = Answer.getLocalBounds();
    Answer.setOrigin(textRect.left + textRect.width/2.0f, heightCenter);
	
    // Main window loop
    thread.launch();

    listener.listen(connectionPort);
    if (listener.accept(socket) == sf::Socket::Done)
    {
	//Success
	cout << "New connection received from: " << socket.getRemoteAddress() << endl;
	ifNext = true;
	thread.wait();
    }	
// jumpToNextStage(window, socket);
}

void ServerMenu::Draw(sf::RenderWindow &window)
{  
    sf::RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(1, 10000));
    rectangle.setOutlineColor(sf::Color::Red);
    rectangle.setOutlineThickness(1);
    rectangle.setPosition(window.getSize().x / 2,  window.getSize().y / 2);
    rectangle.setOrigin(rectangle.getSize().x / 2,  rectangle.getSize().y / 2);
    sf::RectangleShape rectangle1;
    rectangle1.setSize(sf::Vector2f(10000, 1));
    rectangle1.setOutlineColor(sf::Color::Red);
    rectangle1.setOutlineThickness(1);
    rectangle1.setPosition(window.getSize().x / 2,  window.getSize().y / 2);
    rectangle1.setOrigin(rectangle1.getSize().x / 2,  rectangle1.getSize().y / 2);
    sf::RectangleShape rectangle2;
    rectangle2.setSize(sf::Vector2f(1, 10000));
    rectangle2.setOutlineColor(sf::Color::Green);
    rectangle2.setOutlineThickness(1);
    rectangle2.setPosition(window.getSize().x / 2 - 40,  window.getSize().y / 2);
    rectangle2.setOrigin(rectangle.getSize().x / 2,  rectangle.getSize().y / 2);
    sf::RectangleShape rectangle3;
    rectangle3.setSize(sf::Vector2f(1, 10000));
    rectangle3.setOutlineColor(sf::Color::Blue);
    rectangle3.setOutlineThickness(1);
    rectangle3.setPosition(window.getSize().x / 2 + 40,  window.getSize().y / 2);
    rectangle3.setOrigin(rectangle.getSize().x / 2,  rectangle.getSize().y / 2);

    window.clear();
    window.draw(rectangle);
    window.draw(rectangle1);
    window.draw(rectangle2);
    window.draw(rectangle3);
    window.draw(Header);
    window.draw(Question);
    window.draw(Answer);
    
    window.display();
}
