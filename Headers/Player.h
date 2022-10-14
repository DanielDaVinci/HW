#ifndef PRACTICA_PLAYER_H
#define PRACTICA_PLAYER_H

#include <vector>
#include "Board.h"
#include "Domino.h"

using namespace std;

class Player
{
protected:
    Board* board;
    vector<Domino> chips;
public:
    Player(Board* board, vector<Domino>);

    int AmountChips();

    virtual void MakeMove() = 0;
};

#endif
