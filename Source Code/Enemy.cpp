#include "Enemy.hpp"
// Initialize class enemy
Enemy::Enemy()
{
    enemyPresent = false;
    hits = 0;
    health = 80;
}

// Check if the cell in the grid is an enemy
bool Enemy::checkEnemy(char a[][19], int x, int y)
{
    x = x / 32;
    y = y / 32;
    if (a[x][y] == 'E')
        enemyPresent = true;
    else enemyPresent = false;

    return enemyPresent;
}

// If the player finds an enemy decrease his health and increase number of hits
void Enemy::ifYes(char base[][19], int x, int y)
{
    hits++;
    health -= 20;
}
int Enemy::getHITS()
{
    return hits;
}
int Enemy::getHealth()
{
    return health;
}
int Enemy::decHealth()
{
    health = health - 20;
    return health;
}

