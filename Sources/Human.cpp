#include "../Headers/Human.h"

istream & operator >> (istream & in, pair<int, int> & value)
{
    in >> value.first >> value.second;
    return in;
}

Human::Human(Board* board, vector<Domino> chips) : Player(board, chips)
{

}

void Human::MakeMove()
{
    cout << "Your chips: " << endl;
    ShowChips();

    int num;
    cout << "Enter number of chip: ";
    cin >> num;
    num--;

    pair<int, int> firstPos;
    cout << "Enter first position: ";
    cin >> firstPos;

    pair<int, int> secondPos;
    cout << "Enter second position: ";
    cin >> secondPos;

    board->setDomino(chips[num], firstPos, secondPos);
    chips.erase(chips.begin() + num);
}

void Human::ShowChips()
{
    for (int j = 0; j < chips.size(); j++)
        cout << " _  ";
    cout << endl;

    for (int i = 1; i <= 2; i++)
    {
        for (int j = 0; j < chips.size(); j++)
        {
            cout << "|" << ((i == 1) ? chips[j].getFirst() : chips[j].getSecond()) << "| ";
        }
        cout << endl;
    }

    for (int j = 0; j < chips.size(); j++)
        cout << " " << setw(3) << left <<  j + 1;
    cout << endl;
}