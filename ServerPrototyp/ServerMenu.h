#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>


class ServerMenu
{
public:
    ServerMenu(sf::RenderWindow &window);
    void Boot(sf::RenderWindow &window);
private:
    void Lan(sf::RenderWindow &window);
    void Port(sf::RenderWindow &window);
    void CustomPort(sf::RenderWindow &window);
    void Connect(sf::RenderWindow &window);
    void Draw(sf::RenderWindow &window);

    sf::IpAddress ipAddress;
    int connectionPort{6789};
    sf::TcpSocket socket;
    sf::Socket::Status status; 
    sf::TcpListener listener;
    sf::Font font;
    sf::Text Header;
    sf::Text Question;
    sf::Text Answer;
};

