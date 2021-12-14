#ifndef Coin_h
#define Coin_h
#include <SFML/Graphics.hpp>
using namespace sf;
class Coin
{
public:
    Coin();
    bool checkCoin(char a[][19], int x, int y);
    void ifYes(char base[][19], int x, int y, Sprite[][19], Texture&);
    int getCN();
private:
    bool coinPresent;
    int coinNumber = 0;
};
#endif
