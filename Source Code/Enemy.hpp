#ifndef Enemy_h
#define Enemy_h

class Enemy
{
public:
    Enemy();
    bool checkEnemy(char a[][19], int x, int y);
    void ifYes(char base[][19], int x, int y);
    int getHITS();
    int getHealth();
    int decHealth();
    
private:
    bool enemyPresent;
    int hits;
    int health;
};
#endif
