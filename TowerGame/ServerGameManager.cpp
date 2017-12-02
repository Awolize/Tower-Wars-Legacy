#include "ServerGameManager.h"

ServerGameManager::ServerGameManager() 
{
    Tower t1(1, sf::Vector2i(0, 0), 1, 1);
    t1Cost = t1.getCost();
    Tower t2(2, sf::Vector2i(0, 0), 1, 1);
    t2Cost = t2.getCost();
    Soldier s1(1, 1, 1);
    s1Cost = s1.getCost();
    Soldier s2(2, 1, 1);
    s2Cost = s2.getCost();
}

bool ServerGameManager::Run(float coins, float income, int option, int x, int y, Ground &ground)
{
    if(IsBuyAcceptable(coins, option))
	if(ground.IsPlacementAvailable(sf::Vector2i(x,y)))
	    return true;
    return false;
}

bool ServerGameManager::IsBuyAcceptable(float coins, int option)
{
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


