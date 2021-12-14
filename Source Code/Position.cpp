#include "Position.hpp"

Position::Position()
{
    x = 0;
    y = 0;
}
Position::Position(int a, int b)
{
    x = a;
    y = b;
}
void Position::setX(int a)
{
    x = a;
}
void Position::setY(int b)
{
    y = b;
}
int Position::getX()
{
    return x;
}
int Position::getY()
{
    return y;
}
void Position::incX(int v)
{
    x = x + v;
}
void Position::incY(int v)
{
    y = y + v;
}
void Position::decX(int v)
{
    x = x - v;
}
void Position::decY(int v)
{
    y = y - v;
}
Position Position::operator+ (Position b)
{
    Position c;
    c.setX(x + b.getX());
    c.setY(y + b.getY());
    return c;
}
