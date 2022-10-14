#ifndef PRACTICA_COMPUTER_H
#define PRACTICA_COMPUTER_H

#include <tuple>
#include <vector>

#include "Board.h"
#include "Player.h"
#include "History.h"

using namespace std;

class Computer : public Player
{
public:
    Computer(Board*, vector<Domino>);

    void MakeMove() override;
};

#endif
