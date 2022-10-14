#include "../Headers/Domino.h"

Domino::Domino(int first, int second)
{
    values.first = first;
    values.second = second;
}

int Domino::getFirst()
{
    return values.first;
}

int Domino::getSecond()
{
    return values.second;
}