#include "Coin.hpp"
#include <SFML/Graphics.hpp>
using namespace sf;

// Initialize class coin
Coin::Coin()
{
    coinPresent = false;
    coinNumber = 0;
}
// Check if cell in the grid is a coin
bool Coin::checkCoin(char a[][19], int x, int y)
{
    x = x / 32;
    y = y / 32;
    if (a[x][y] == 'C')
        coinPresent = true;
    else coinPresent = false;

    return coinPresent;
}

// If the player finds a coin erase it and increase his coin number
void Coin::ifYes(char base[][19], int x, int y, Sprite tile[][19], Texture& ground)
{
    coinNumber++;
    x = x / 32;
    y = y / 32;
    base[x][y] = '.';
    tile[x][y].setTexture(ground);
}

// Get amount of coins player has
int Coin::getCN()
{
    return coinNumber;
}
