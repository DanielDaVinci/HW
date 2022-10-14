#include "../Headers/Player.h"

Player::Player(Board* board, vector<Domino> chips)
{
    this->board = board;
    this->chips = chips;
}

int Player::AmountChips()
{
    return chips.size();
}