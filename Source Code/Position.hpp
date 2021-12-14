#ifndef Position_h
#define Position_h
class Position
{
public:
    Position();
    Position(int a, int b);
    void setX(int a);
    void setY(int b);
    int getX();
    int getY();
    void incX(int v);
    void incY(int v);
    void decX(int v);
    void decY(int v);
    Position operator+ (Position b);

private:
    int x;
    int y;
      /* int x;
    int y;
        int direction=1;

  //  void GhostAI(Enemy &ghost, Game &player);
    int Ai_coordinates;*/
};
#endif
