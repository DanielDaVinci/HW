#ifndef PRACTICA_BOARD_H
#define PRACTICA_BOARD_H

#include <iostream>
#include <iomanip>
#include <cmath>
#include <tuple>

#include "Domino.h"
#include "History.h"

using namespace std;

class Board
{
public:
    static const int SIZE = 10;
    History history;
private:
    char matrix[SIZE][SIZE];
public:
    Board();

    void setDomino(Domino, pair<int, int>, pair<int, int>);
    int getValue(pair<int, int>);
    int getValue(int, int);

    void Print();
    void PrintDiagnostic();
};

#endif
