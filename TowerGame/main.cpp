#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>

using namespace std;

int main()
{
    sf::IpAddress ip = sf::IpAddress::getLocalAddress();
    sf::TcpSocket socket;
    char connectionType;
    int connectionPort;

    cout << "Enter (s) for Server, Enter (c) for Client: ";
    cin >> connectionType;
    cout << "Enter port used for the connection: ";
    cin >> connectionPort;

    if(connectionType == 's')
    {
	sf::TcpListener listener;
	listener.listen(connectionPort);
	listener.accept(socket);
	cout << "Server: " << endl;;
    }
    else
    {
	socket.connect(ip, connectionPort);
	cout << "Client: " << endl;;
    } 
	

    sf::RectangleShape rect1, rect2;

    rect1.setSize(sf::Vector2f(20, 20));
    rect2.setSize(sf::Vector2f(20, 20));
    
    rect1.setFillColor(sf::Color::Red);
    rect2.setFillColor(sf::Color::Blue);

    sf::RenderWindow window(sf::VideoMode(800, 600), "Packets", sf::Style::Close | sf::Style::Resize);

    sf::Vector2f prevPos, p2Pos;
    socket.setBlocking(false);
    bool update = false;

    while (window.isOpen())
    {
	sf::Event Event;
	while (window.pollEvent(Event))
	{
	    if (Event.type == sf::Event::Closed || Event.key.code == sf::Keyboard::Escape)
		window.close();
	    else if (Event.type == sf::Event::GainedFocus)
		update = true;
	    else if (Event.type == sf::Event::LostFocus)
		update = false;
	}
	
	prevPos = rect1.getPosition();

	if(update)
	{
	    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		rect1.move(1.0f, 0.0f);
	    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		rect1.move(-1.0f, 0.0f);
	    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		rect1.move(0.0f, -1.0f);
	    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		rect1.move(0.0f, 1.0f);
	}

	sf::Packet packet;

	if (prevPos != rect1.getPosition())
	{
	    packet << rect1.getPosition().x << rect1.getPosition().y;
	    socket.send(packet);
	}

	socket.receive(packet);
	if (packet >> p2Pos.x >> p2Pos.y)
	    rect2.setPosition(p2Pos);

	window.draw(rect1);
	window.draw(rect2);

	window.display();
	window.clear();

       
    }
}
