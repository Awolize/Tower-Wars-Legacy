#include "ServerGameManager.h"

ServerGameManager::ServerGameManager() 
{
    Tower t1(1,1);
    t1Cost = t1.GetCost();
    Tower t2(1,1);
    t2Cost = t2.GetCost();
    Soldier s1(1,1);
    s1Cost = s1.GetCost();
    Soldier s2(2,1);
    s2Cost = s2.GetCost();
}

bool ServerGameManager::Run(float coins, float income, int option, int x, int y, Ground ground)
{
    if(IsBuyAcceptable(coins, option))
	if(IsPlacementAcceptable(x, y))
//	    if(ooooo())
		return true;
    return false;
}

bool ServerGameManager::IsBuyAcceptable(float coins, int option)
{
    if(option == 1 || option == 2)
    {
	if(t1Cost - coins >= 0 || t2Cost - coins >= 0)
	    return true;       
	else
	    return false;
    }
    if(option == 3 || option == 4)
    {
	if(s1Cost - coins >= 0 || s2Cost - coins >= 0)
	    return true;
	else
	    return false;
    }

}

bool ServerGameManager::IsPlacementAcceptable(int x , int y)
{
    return true;
//Check if ground matrix position is available

}


