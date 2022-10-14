#ifndef PRACTICA_DOMINO_H
#define PRACTICA_DOMINO_H

#include <tuple>

using namespace std;

class Domino
{
private:
    pair<int, int> values;
public:
    Domino(int first = 0, int second = 0);

    int getFirst();
    int getSecond();
};

#endif