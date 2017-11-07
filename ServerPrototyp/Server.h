#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>

class Server
{
public:
    Server();
    ~Server();
    void Run();
private:
    void Init();
    void Connect();

    sf::IpAddress ipAddress;
    int connectionPort{6789};
    sf::Socket::Status status; 
    sf::TcpListener listener;
    sf::TcpSocket clientSocket;

};

