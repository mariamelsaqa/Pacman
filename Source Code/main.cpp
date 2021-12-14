
//
// Disclaimer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resources, use the helper
// function `resourcePath()` from ResourcePath.hpp
//

#include <SFML/Graphics.hpp>
#include "Position.hpp"
#include "Coin.hpp"
#include "Enemy.hpp"
#include "win.hpp"
#include "Game.hpp"
#include "Graph.hpp"
#include <string>
#include <time.h>
#include <cctype>
#include <iostream>
using namespace sf;
using namespace std;

int main()
{
    // Declaration of variables
    Clock clock; // to calculate elapsed time.
    int timeRunning, timeInterface; // the time elapsed of the game and time of the interface respectively.
    Coin coin13; // the class coin
    Enemy enemy13; // the class enemy
    Win winning; // class winning
    int timeTaken; // the time player took to finish level
    Game project; // class game
    Position posE1, posE2; //Ghost Position
    PowerCoin powercoin13;

    srand(time(NULL));

    project.makeText();
    project.makeAllT();
    project.makeAllS();

    RenderWindow interface(VideoMode(608, 672), "Pacman!");

    while (interface.isOpen())
    {
        timeInterface = clock.getElapsedTime().asSeconds();

        project.makeInterface(interface);

        Event m;
        while (interface.pollEvent(m))
        {
            switch (m.type)
            {
            case Event::KeyPressed:
                switch (m.key.code)
                {
                case Keyboard::Escape:
                    interface.close();
                    break;
                case Keyboard::N:
                {
                                    interface.close();
                                    // Setting the window
                                    RenderWindow win(VideoMode(608, 672), "Pacman!");
                                    project.readMap();

                                    // A loop to read the rest of the file and fetch coins /enemies/ target etc..
                                    project.readRest();
                                    Position pos(project.getXPLAYER(), project.getYPLAYER());

                                    project.topBar();

                                    while (win.isOpen())
                                    {
                                        timeRunning = clock.getElapsedTime().asSeconds() - timeInterface;

                                        project.getEnemyCoordinates();
                                    
                                        Position posE1(14 * 32, 2 * 32);
                                        Position posE2(9 * 32, 8 * 32);
                                        Position posE3(4 * 32, 11 * 32);
                                        Position posE4(14 * 32, 19 * 32);

                                        Event e;
                                        while (win.pollEvent(e))
                                        {
                                            switch (e.type)
                                            {
                                            case Event::KeyPressed:
                                                switch (e.key.code)
                                                {
                                                case Keyboard::Escape:
                                                    win.close();
                                                    break;
                                                case Keyboard::Up:
                                                    project.move2(pos, coin13,powercoin13, enemy13, winning, win, 0);
                                                    break;
                                                case Keyboard::Down:
                                                    project.move2(pos, coin13,powercoin13, enemy13, winning, win, 1);
                                                    break;
                                                case Keyboard::Left:
                                                    project.move2(pos, coin13,powercoin13, enemy13, winning, win, 2);
                                                    break;
                                                case Keyboard::Right:
                                                    project.move2(pos, coin13,powercoin13, enemy13, winning, win, 3);
                                                    break;
                                                }
                                                break;
                                            }
                                        }

                                        switch (timeRunning % 4)
                                        {
                                        case 0:
                                            project.moveEnemy(posE1, 0, pos, enemy13);
                                            project.moveEnemy(posE2, 0, pos, enemy13);
                                            project.moveEnemy(posE3, 0, pos, enemy13);
                                            project.moveEnemy(posE4, 0, pos, enemy13);
                                            break;
                                        case 1:
                                            project.moveEnemy(posE1, 1, pos, enemy13);
                                            project.moveEnemy(posE2, 1, pos, enemy13);
                                            project.moveEnemy(posE3, 1, pos, enemy13);
                                            project.moveEnemy(posE4, 1, pos, enemy13);
                                            break;
                                        case 2:
                                            project.moveEnemy(posE1, 2, pos, enemy13);
                                            project.moveEnemy(posE2, 2, pos, enemy13);
                                            project.moveEnemy(posE3, 2, pos, enemy13);
                                            project.moveEnemy(posE4, 2, pos, enemy13);
                                            break;
                                        case 3:
                                            project.moveEnemy(posE1, 3, pos, enemy13);
                                            project.moveEnemy(posE2, 3, pos, enemy13);
                                            project.moveEnemy(posE3, 3, pos, enemy13);
                                            project.moveEnemy(posE4, 3, pos, enemy13);
                                            break;
                                        }

                                        // Updating the scene
                                        project.updateAndDraw(pos, win, timeRunning, coin13, enemy13, posE1, posE2, posE3, posE4);
                                    }
                                    return 0;
                }
                    break;
                }
            }
        }
    }
    //shortest path algorithm
    
        char arr[21][19]={
        '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',
        '#','$','.','.','.','.','.','.','.','#','.','.','.','.','$','.','.','.','#',
        '#','.','#','#','.','#','#','#','.','#','.','#','#','#','$','#','#','.','#',
        '#','.','.','.','.','.','.','.','.','.','.','.','.','.','$','.','.','.','#',
        '#','.','#','#','.','#','.','#','#','#','#','#','.','#','.','#','#','.','#',
        '#','.','.','.','.','#','.','.','.','#','.','.','.','#','.','.','.','.','#',
        '#','#','#','#','.','#','#','#','.','#','.','#','#','#','.','#','#','#','#',
        '#','#','#','#','.','#','.','.','.','$','.','.','.','#','.','#','#','#','#',
        '#','#','#','#','.','#','.','#','#','$','#','#','.','#','.','#','#','#','#',
        '$','$','$','$','.','.','.','#','$','$','$','#','.','.','.','$','$','$','$',
        '#','#','#','#','$','#','.','#','#','#','#','#','.','#','.','#','#','#','#',
        '#','#','#','#','$','#','.','.','.','.','.','.','.','#','.','#','#','#','#',
        '#','#','#','#','$','#','.','#','#','#','#','#','.','#','.','#','#','#','#',
        '#','.','.','.','.','.','.','.','.','#','.','.','.','.','.','.','.','.','#',
        '#','.','#','#','.','#','#','#','.','#','.','#','#','#','.','#','#','.','#',
        '#','.','.','#','.','.','.','.','.','.','.','.','.','.','.','#','.','.','#',
        '#','#','.','#','.','#','.','#','#','#','#','#','.','#','.','#','.','#','#',
        '#','.','.','.','.','#','.','.','.','#','.','.','.','#','.','.','.','.','#',
        '#','.','#','#','#','#','#','#','.','#','.','#','#','#','#','#','#','.','#',
        '#','.','.','.','.','.','.','.','.','.','.','.','.','$','$','$','.','.','#',
        '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',
        };
        Graph g(399);
        int names[21][19];
        int node=0;
        
        for (int i=0; i<21; i++) {
            for (int j =0; j<19; j++) {
                if( j+1 < 19)
                    if (arr[i][j+1] == '#')
                        g.addEdge(names[i][j], names[i][j+1]);
                
                if( j-1 >= 0)
                    if (arr[i][j-1] == '#' )
                        g.addEdge(names[i][j],names[i][j-1]);
                
                if( i-1 >= 0)
                    if (arr[i-1][j] == '#' )
                        g.addEdge(names[i][j],names[i-1][j]);
                
                
                if( i+1 < 19)
                    if (arr[i+1][j] == '#' )
                        g.addEdge(names[i][j],names[i+1][j]);
                
            }
        }
        
        
        int source = 0, dest = 99;
        g.printDist(source, dest);
return 0;
}

