#include <iostream>
#include <vector>
#include <random>

#include "Headers/Board.h"
#include "Headers/Human.h"
#include "Headers/Computer.h"
#include "Headers/Domino.h"

using namespace std;

int main()
{
    vector<Domino> pool = vector<Domino>(28);
    for (int i = 0, counter = 0; i <= 6; i++)
    {
        for (int j = i; j <= 6; j++)
        {
            pool[counter] = Domino(i, j);
            counter++;
        }
    }

    srand(time(0));
    vector<Domino> humanChips;
    for (int i = 0; i < 14; i++)
    {
        int pos = rand() % pool.size();
        humanChips.push_back(pool[pos]);
        pool.erase(pool.begin() + pos);
    }

    Board board;
    Human human(&board, humanChips);
    Computer computer(&board, pool);

    board.Print();

    while (human.AmountChips() != 0 && computer.AmountChips() != 0)
    {
        human.MakeMove();
        board.Print();
        computer.MakeMove();
        board.Print();
    }

    board.PrintDiagnostic();
    return 0;
}
