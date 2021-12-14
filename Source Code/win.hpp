#ifndef Win_h
#define Win_h

#include "Coin.hpp"

class Win
{
public:
    Win();
    bool checkWin();
private:
    bool win;
    Coin C;
};
#endif
