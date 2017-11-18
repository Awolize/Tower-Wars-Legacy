#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>


class Server
{
public:
    Server(sf::RenderWindow &window);
    ~Server();
    void Boot(sf::RenderWindow &window);
private:
    void Lan(sf::RenderWindow &window);
    void Port(sf::RenderWindow &window);
    void CustomPort(sf::RenderWindow &window);
    void Connect(sf::RenderWindow &window);
    void Draw(sf::RenderWindow &window);

    sf::IpAddress ipAddress;
    int connectionPort{6789};
    sf::Socket::Status status; 
    sf::TcpListener listener;
    sf::TcpSocket clientSocket;
    sf::RectangleShape IpAddressTextBox;
    sf::Font font;
    sf::Text Question;
    sf::Text Answer;
    std::string strPort = "";
};

