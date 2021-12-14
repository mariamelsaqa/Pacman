#include "win.hpp"
#include "Coin.hpp"
Win::Win()
{
    win = false;
}

    bool Win::checkWin(){
        //check if there is no coins
  if (C.getCN() == 0)
      win = true;
      else
          win = false;
    
      return win;
}

