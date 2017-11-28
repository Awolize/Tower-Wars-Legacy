#ifndef SERVERGAMEMANAGER_H
#define SERVERGAMEMANAGER_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "Player.h"
#include "Soldier.h"
#include "Ground.h"

class ServerGameManager
{
public:
    ServerGameManager();
    bool Run(float coins, float income, int option, int x, int y, Ground ground);

private:
    bool IsPlacementAcceptable(int x, int y);
    bool IsBuyAcceptable(float coins, int option);

    int s1Cost;
    int s2Cost;
    int t1Cost;
    int t2Cost;   
};

#endif
