#ifndef Game_h
#define Game_h
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <fstream>
#include <sstream>
#include "Coin.hpp"
#include "Enemy.hpp"
#include "Position.hpp"
#include "win.hpp"
#include "PowerCoin.hpp"
#include <vector>
using namespace sf;
using namespace std;
class Game
{
public:
    Game();
    bool checkWalk(int, int, int); // check walls and grid
    void checkStart(string, string, int& x, int& y);
    void makeTexture(Texture&, string);
    void readMap();
    void readRest();
    void topBar();
    void move2(Position&, Coin&, PowerCoin&, Enemy&, Win&, RenderWindow&, int);
    void updateAndDraw(Position&, RenderWindow&, int, Coin&, Enemy&, Position&, Position&, Position&, Position&);
    void lose(int, Enemy&, RenderWindow&);
    void makeText();
    void makeInterface(RenderWindow&);
    void moveEnemy(Position&, int,Position &,Enemy&);
    void getEnemyCoordinates();
    int getXPLAYER();
    int getBonus();
    int getYPLAYER();
    void makeAllS();
    void makeAllT();
private:
    bool okToWalk;
    int xEnemy, yEnemy;
    int countEnemy;
    int xCoin, yCoin;
    int xPlayer, yPlayer;
    int Bonus;
    int maxTime;
    vector <int> EnemyX;
    vector <int> EnemyY;
    char base[21][19];  // The basic base in a 2D array.
    Text score, time, health2;
    Font font;
    SoundBuffer move;   // sound effect for each key press
    std::ifstream map1;
    Sound tap;
    Sprite tile[21][19];
    Texture interface1;
    Sprite interface2;
    Texture character;
    Texture ground;
    Texture wall;
    Texture ally;
    Sprite Enemy1, Enemy2, Enemy3, Enemy4;
    Texture besideIcon;
    Texture clockIcon;
    Texture healthIcon;
    Texture scoreIcon;
    Texture coin;
    Texture youWin;
    Texture youLost;
    Texture monster;
    Texture blinky;
    Texture inky;
    Texture pinky;
    Texture clyde;
    Sprite player;
    Sprite coin1;
    Sprite youWin1;
    Sprite youLost1;
    Coin C;
    Enemy h;
    Texture PowerCoin;
    Sprite PowerCoin1;
    Texture VulnerableGhost;
    Sprite VulGhost;
};
#endif
