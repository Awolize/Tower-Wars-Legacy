#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>

#include "Server.h"
#include "Client.h"

using namespace std;

int main()
{
    int MenuOption;
    bool mainLoop = true;

    while(mainLoop)
    {
	cout << endl;
	cout << "--Main menu--" << endl;
	cout << "1. Server " << endl;
	cout << "2. Client " << endl;
	cout << "3. Quit " << endl;;
	cout << "Choice: ";
	cin >> MenuOption;
	cout << endl;

	if(MenuOption == 1)
	{
	    Server server;
	    server.Run();
	    mainLoop = false;
	    
	}
	else if(MenuOption == 2)
	{
	    Client client; 
	    client.Run();
	    mainLoop = false;
	}
	else 
	{
	    cout << "Stopping program... " << endl;
	    mainLoop = false;
	}
    }
    cout << endl;
}
