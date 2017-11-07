#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>

class Client
{
public:
    Client();
    ~Client();
    void Run();

private:
    void Init();
    void Connect();
    
    sf::IpAddress ipAddress;
    int connectionPort{6789};
    sf::TcpSocket socket;
    sf::Socket::Status status; 
};


