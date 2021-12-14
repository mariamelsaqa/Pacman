//
//  PowerCoin.cpp
//  PacmanFinal
//
//  Created by Mariam Elsaqa on 5/22/20.
//  Copyright © 2020 None. All rights reserved.
//
#include "PowerCoin.hpp"
#include <SFML/Graphics.hpp>
using namespace sf;

// Initialize class Power Coin
PowerCoin::PowerCoin()
{
    PowercoinPresent = false;
}
// Check if cell in the grid is a Power coin
bool PowerCoin::checkPowerCoin(char a[][19], int x, int y)
{
    x = x / 32;
    y = y / 32;
    if (a[x][y] == 'P')
        PowercoinPresent = true;
    else PowercoinPresent = false;

    return PowercoinPresent;
}

// If the player finds a Power coin erase it
void PowerCoin::ifYes(char base[][19], int x, int y, Sprite tile[][19], Texture& ground ,Texture& GhostAfraid)
{
    tile[14][2].setTexture(GhostAfraid);
    tile[9][8].setTexture(GhostAfraid);
    tile[4][11] .setTexture(GhostAfraid);
    tile[14][18] .setTexture(GhostAfraid);
    x = x / 32;
    y = y / 32;
    base[x][y] = '.';
    tile[x][y].setTexture(ground);
    
}

