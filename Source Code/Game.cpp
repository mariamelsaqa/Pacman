#include "Game.hpp"
#include "Coin.hpp"
#include "Enemy.hpp"
#include "win.hpp"
#include "Position.hpp"
#include "PowerCoin.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <fstream>
#include <cctype>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include "ResourcePath.hpp"
using namespace sf;
using namespace std;
Game::Game()
{
    okToWalk = true;
    xCoin = 0;
    yCoin = 0;
    Bonus = 0;
    font.loadFromFile(resourcePath() + "sansation.ttf");
    move.loadFromFile(resourcePath() + "tap.wav");
    
    tap.setBuffer(move);
    map1.open(resourcePath() + "map.txt");
}
//check for the walls and ground
bool Game::checkWalk(int x, int y, int i)
{
    switch (i)
    {
    case 0:
        if ((base[(y - 32) / 32][x / 32] == '#') || (y <= 17))
            okToWalk = false;
        else okToWalk = true;
        break;
    case 1:
        if ((base[(y + 32) / 32][x / 32] == '#') || (y >= 608))
            okToWalk = false;
        else okToWalk = true;
        break;
    case 2:
        if ((base[y / 32][(x - 32) / 32] == '#') || (x <= 17))
            okToWalk = false;
        else okToWalk = true;
        break;
    case 3:
        if ((base[y / 32][(x + 32) / 32] == '#') || (x >= 672))
            okToWalk = false;
        else okToWalk = true;
        break;
    }

    return okToWalk;
}
//reads from a file to print it
//32 is the number of pixels
void Game::checkStart(string c, string a, int& x, int& y)
{
    if (c == a)
    {
        map1 >> x;
        x = x * 32;
        cout << x << endl;
        map1 >> y;
        y = x * 32;
        cout << y << endl;
    }
}
int Game::getXPLAYER()
{
    return xPlayer;
}
int Game::getYPLAYER()
{
    return yPlayer;
}

void Game::makeTexture(Texture& t, string s)
{
    t.loadFromFile(s.c_str());
}
void Game::makeAllT()
{
    makeTexture(character, resourcePath() + "character.png");

    makeTexture(ground, resourcePath() + "groundX.png");
    makeTexture(wall, resourcePath() + "wallX.png");
    makeTexture(besideIcon, resourcePath() + "besideIcon.png");
    makeTexture(clockIcon, resourcePath() + "clock.png");
    makeTexture(healthIcon, resourcePath() + "heart.png");
    makeTexture(scoreIcon, resourcePath() + "score.png");
    makeTexture(coin, resourcePath() + "coinX.png");
    makeTexture(youWin, resourcePath() + "YouWin.png");
    makeTexture(youLost, resourcePath() + "YouLost.png");
   // makeTexture(monster, resourcePath() + "monster.png");
    makeTexture(blinky, resourcePath()+"blinky.png");
    makeTexture(clyde, resourcePath()+"clyde.png");
    makeTexture(pinky, resourcePath()+"pinky.png");
    makeTexture(inky, resourcePath()+"inky.png");
    makeTexture(scoreIcon, resourcePath() + "score.png");
    makeTexture(PowerCoin, resourcePath()+ "fruitx.jpg");
    makeTexture(VulnerableGhost, resourcePath()+"Afraidx.jpg");
}
void Game::readMap()
{
    char f;
    for (int i = 0; i < 21; i++)
    {
        for (int j = 0; j < 19; j++)
        {
            map1 >> f;
            base[i][j] = f;
            if (base[i][j] == '#')
            {
                tile[i][j].setTexture(wall);
            }
            else
                tile[i][j].setTexture(ground);
        }
    }
}
void Game::makeAllS()
{
    player.setTexture(character);
    coin1.setTexture(coin);
    youWin1.setTexture(youWin);
    youLost1.setTexture(youLost);
    Enemy1.setTexture(blinky);
    Enemy2.setTexture(clyde);
    Enemy3.setTexture(inky);
    Enemy4.setTexture(pinky);
   // Enemy1.setTexture(monster);
    PowerCoin1.setTexture(PowerCoin);
    VulGhost.setTexture(VulnerableGhost);
}
void Game::readRest()
{
    // Initialize player position
    xPlayer = 32;
    yPlayer = 32;
        
    //pellets
    for (int i=0;i<21; i++){
        for (int j=0;j<19; j++){
            if( base[i][j] != 'E' && base[i][j] != '#' && base[i][j] != '$'){
                tile[i][j].setTexture(coin);
                base[i][j]= 'C';
            }
        }
    }
    
    //Initialize Power Coin
    tile[4][1].setTexture(PowerCoin);
    tile[4][17].setTexture(PowerCoin);
    tile[17][1].setTexture(PowerCoin);
    tile[17][17].setTexture(PowerCoin);
    
    
    // Initialize enemy positions
    base[14][2] = 'E';
    base[9][8] = 'E';
    base[4][11] = 'E';
    base[14][18] = 'E';
    
    
    // Setting max time
    maxTime = 100;
    
}
void Game::getEnemyCoordinates()
{
    for (int i = 0; i < 21; i++)
    {
        for (int j = 0; j < 19; j++)
        {
            if (base[i][j] == 'E')
            {
                EnemyX.push_back(i);
                EnemyY.push_back(j);
            }
        }
    }
}
void Game::topBar()
{
    tile[0][1].setTexture(scoreIcon);
    tile[0][2].setTexture(besideIcon); // this box is reserved to display score
    tile[0][5].setTexture(clockIcon);
    tile[0][6].setTexture(besideIcon); // this box is reserved to display time
    tile[0][9].setTexture(healthIcon);
    tile[0][10].setTexture(besideIcon); // this box is reserved to display health
}
void Game::move2(Position& pos, Coin &coin13, class PowerCoin &powercoin13, Enemy &enemy13, Win &winning, RenderWindow& win, int i)
{
    if (checkWalk(pos.getX(), pos.getY(), i)) // first check for grid and walls
    {
        switch (i)
        {
        case 0:
            pos.decY(32);
            break;
        case 1:
            pos.incY(32);
            break;
        case 2:
            pos.decX(32);
            break;
        case 3:
            pos.incX(32);
            break;
        }
        /*if (getXPLAYER()== 11 && getYPLAYER()== 0){
            xPlayer= 11;
            yPlayer= 18;
        }*/
        if (coin13.checkCoin(base, pos.getY(), pos.getX())) // check if the next movement has a coin
            coin13.ifYes(base, pos.getY(), pos.getX(), tile, ground);
        else
        if (enemy13.checkEnemy(base, pos.getY(), pos.getX())) // check if the next movement has an enemy
        {
            enemy13.ifYes(base, pos.getY(), pos.getX());
            pos.setX(32);
            pos.setY(32);
        }
        else
            if (winning.checkWin()== 0) //check if there is any coins left
        {
            RenderWindow YOUWIN(VideoMode(608, 672), "Pacman!, you win!");
            win.close();
            while (YOUWIN.isOpen())
            {
                YOUWIN.draw(youWin1);
                YOUWIN.display();
            }
        }
        else
            if(powercoin13.checkPowerCoin(base, pos.getY(), pos.getX())) //check if next movement has a power coin
            {
               powercoin13.ifYes(base,pos.getY(), pos.getX(), tile, ground, VulnerableGhost);
            }
    }
}
void Game::updateAndDraw(Position &pos, RenderWindow& win, int timeRunning, Coin& coin13, Enemy& enemy13, Position& E1, Position& E2, Position& E3, Position& E4)
{
    player.setPosition(pos.getX(), pos.getY());
    Enemy1.setPosition(E1.getX(), E1.getY());
    Enemy2.setPosition(E2.getX(), E2.getY());
    Enemy3.setPosition(E3.getX(), E3.getY());
    Enemy4.setPosition(E4.getX(), E4.getY());


    for (int i = 0; i < 21; i++)
    for (int j = 0; j < 19; j++)
        tile[i][j].setPosition(j * 32, i * 32);

    for (int i = 0; i < 21; i++)
    for (int j = 0; j < 19; j++)
        win.draw(tile[i][j]);

    win.draw(player);
    win.draw(Enemy1);
    win.draw(Enemy2);
    win.draw(Enemy3);
    win.draw(Enemy4);

    stringstream displayTime;
    displayTime << timeRunning;
    time.setString(displayTime.str());
    time.setPosition(198.5, 4);
    win.draw(time);

    stringstream ss;
    ss << coin13.getCN();
    score.setString(ss.str());
    score.setPosition(72, 0);
    win.draw(score);

    stringstream HP;
    HP << enemy13.getHealth();
    health2.setString(HP.str());
    health2.setPosition(323, 3);
    win.draw(health2);

    win.display();
}
void Game::lose(int timeRunning, Enemy& enemy13, RenderWindow& win)
{
    if ((timeRunning >= maxTime) || (enemy13.getHealth() == 0))
    {
        RenderWindow lose(VideoMode(608, 672), "Pacman., you lost!");
        win.close();
        while (lose.isOpen())
        {
            lose.draw(youLost1);
            lose.display();
        }
    }
}
void Game::makeText()
{
    score.setColor(Color::White);
    score.setFont(font);
    score.setStyle(Text::Bold);
    score.setCharacterSize(25);

    time.setColor(Color::White);
    time.setFont(font);
    time.setStyle(Text::Bold);
    time.setCharacterSize(17);

    health2.setColor(Color::White);
    health2.setFont(font);
    health2.setStyle(Text::Bold);
    health2.setCharacterSize(17);
}
void Game::makeInterface(RenderWindow& interface)
{
    interface1.loadFromFile(resourcePath() + "Interface.png");
    interface2.setTexture(interface1);
    interface.draw(interface2);
    interface.display();
}
int Game::getBonus()
{
    return Bonus;
}
void Game::moveEnemy(Position& E, int i,Position &pos,Enemy &enemy13)
{
    if (checkWalk(E.getX(), E.getY(), i)) // first check for grid and walls
    {
        base[E.getX() / 32][E.getY() / 32] = '.';
        switch (i)
        {
        case 0:
        {
                  
                  E.decY(32);
                  base[E.getX() / 32][E.getY() / 32] = 'E';
                  if (pos.getX() == E.getX() && pos.getY() == E.getY())
                  {
                      enemy13.decHealth();
                      pos.setX(32);
                      pos.setY(32);
                  }
        }
            break;
        case 1:
        {
                 
                  E.incY(32);
                  base[E.getX() / 32][E.getY() / 32] = 'E';
                  if (pos.getX() == E.getX() && pos.getY() == E.getY())
                  {
                      enemy13.decHealth();
                      pos.setX(32);
                      pos.setY(32);
                  }
        }
            break;
        case 2:
        {
                 
                  E.decX(32);
                  base[E.getX() / 32][E.getY() / 32] = 'E';
                  if (pos.getX() == E.getX() && pos.getY() == E.getY())
                  {
                      enemy13.decHealth();
                      pos.setX(32);
                      pos.setY(32);
                  }
        }
            break;
        case 3:
        {
                 
                  E.incX(32);
                  base[E.getY() / 32][E.getX() / 32] = 'E';
                  if (pos.getX() == E.getX() && pos.getY() == E.getY())
                  {
                      enemy13.decHealth();
                      pos.setX(32);
                      pos.setY(32);
                  }
        }
            break;
        }

    }
}

// this is the AI of the ghost using pythagorous theroem
/*
void Enemy::GhostAI(Enemy &ghost, Game &player)
{
    double a = sqrt((pow((double) (xEnemy - 1) - xPlayer, 2)) + pow((double) yEnemy - yPlayer, 2)); //UP
    double b = sqrt((pow((double) (xEnemy + 1) - xPlayer, 2)) + pow((double) yEnemy - yPlayer, 2)); //DOWN
    double c = sqrt((pow((double) (yEnemy - 1) - xPlayer, 2)) + pow((double) xEnemy - yPlayer, 2)); //RIGHT
    double d = sqrt((pow((double) (yEnemy + 1) - xPlayer, 2)) + pow((double) xEnemy - yPlayer, 2)); //LEFT
    if(a < b && a <= c && a <= d && Enemy.direction != 2) Enemy.direction = 1;//UP
    else if(b <= c && b <= d && Enemy.direction != 1) Enemy.direction = 2;//DOWN
    else if(c < d && Enemy.direction != 4) Enemy.direction = 3;//RIGHT
    else if(Enemy.direction != 3) ghost.direction = 4;//LEFT
}
}
*/
