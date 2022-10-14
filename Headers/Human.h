#ifndef PRACTICA_HUMAN_H
#define PRACTICA_HUMAN_H

#include <iostream>

#include "Board.h"
#include "Player.h"

using namespace std;

class Human : public Player
{
public:
    Human(Board* board, vector<Domino>);

    void MakeMove() override;
    void ShowChips();
};

#endif
