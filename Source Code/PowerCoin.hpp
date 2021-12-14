//
//  PowerCoin.hpp
//  PacmanFinal
//
//  Created by Mariam Elsaqa on 5/22/20.
//  Copyright © 2020 None. All rights reserved.
//

#ifndef PowerCoin_hpp
#define PowerCoin_hpp
#include <SFML/Graphics.hpp>
using namespace sf;

class PowerCoin{
public:
    PowerCoin();
    bool checkPowerCoin(char a[][19], int x, int y);
    void ifYes(char base[][19], int x, int y, Sprite[][19], Texture&, Texture&);
    
private:
    bool PowercoinPresent;
};

#endif /* PowerCoin_hpp */
