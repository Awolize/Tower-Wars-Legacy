#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>

class Client
{
public:
    Client();
    ~Client();
    void Boot(sf::RenderWindow &window);

private:
    void Init(sf::RenderWindow &window);
    void Connect(sf::RenderWindow &window);
    
    sf::IpAddress ipAddress;
    int connectionPort{6789};
    sf::TcpSocket socket;
    sf::Socket::Status status; 
};


