#include "ServerGameManager.h"

#include <iostream>
using namespace std;

ServerGameManager::ServerGameManager() 
{
    Tower t1(1);
    t1Cost = t1.getCost();
    Tower t2(2);
    t2Cost = t2.getCost();
    Soldier s1(3);
    s1Cost = s1.getCost();
    Soldier s2(4);
    s2Cost = s2.getCost();
}

bool ServerGameManager::Run(float coins, float income, int option, int x, int y, Ground &ground)
{
    if (option == 5)
    {
	if(!ground.IsPlacementAvailable(sf::Vector2i(x,y)))
	{
	    ground.SellTower(sf::Vector2i(x,y));
	    return true;
	}
    }
    else if(IsBuyAcceptable(coins, option))
	if(ground.IsPlacementAvailable(sf::Vector2i(x,y)))
	    return true;
    return false;
}

bool ServerGameManager::IsBuyAcceptable(float coins, int option)
{
    cout << coins << endl;
    if(option == 1)
    {
	if (coins >= t1Cost)
	    return true;       
    }
    else if(option == 2)
    {
	if (coins >= t2Cost)
	    return true;     
    }
    else if (option == 3 )
    {
	if (coins >= s1Cost)
	    return true;
    }
    else if (option == 4)
    {
	if (coins >= s2Cost)
	    return true;
    }
    return false;
}


