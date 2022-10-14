#include "../Headers/Computer.h"

/*
template <typename T1,typename T2>
pair<T1,T2> operator - (pair<T1, T2> & left, pair<T1, T2> & right)
{
    return { left.first - right.first, left.second - right.second};
}

pair<int, int> operator - (pair<int, int> & left, pair<int, int> & right)
{
    return { left.first - right.first, left.second - right.second};
}
*/

Computer::Computer(Board* board, vector<Domino> chips) : Player(board, chips)
{

}

void Computer::MakeMove()
{
    pair<int, int> firstPos = make_pair(board->SIZE, board->SIZE);
    firstPos.first -= board->history.getLastMove().first.first - 1;
    firstPos.second -= board->history.getLastMove().first.second - 1;

    pair<int, int> secondPos = make_pair(board->SIZE, board->SIZE);
    secondPos.first -= board->history.getLastMove().second.first - 1;
    secondPos.second -= board->history.getLastMove().second.second - 1;

    vector<int> valuesInArea;
    valuesInArea.push_back(board->getValue({ firstPos.first - 1, firstPos.second }));
    valuesInArea.push_back(board->getValue({ firstPos.first + 1, firstPos.second }));
    valuesInArea.push_back(board->getValue({ firstPos.first, firstPos.second - 1 }));
    valuesInArea.push_back(board->getValue({ firstPos.first, firstPos.second + 1 }));

    valuesInArea.push_back(board->getValue({ secondPos.first - 1, secondPos.second }));
    valuesInArea.push_back(board->getValue({ secondPos.first + 1, secondPos.second }));
    valuesInArea.push_back(board->getValue({ secondPos.first, secondPos.second - 1 }));
    valuesInArea.push_back(board->getValue({ secondPos.first, secondPos.second + 1 }));

    int i;
    for (i = 0; i < chips.size(); i++)
    {
        for (int j = 0; j < valuesInArea.size(); j++)
        {
            if (chips[i].getFirst() == valuesInArea[j])
            {
                if (j + 1 > valuesInArea.size() / 2)
                    swap(firstPos, secondPos);
                goto exit;
            }
            else if (chips[i].getSecond() == valuesInArea[j])
            {
                if (j + 1 <= valuesInArea.size() / 2)
                    swap(firstPos, secondPos);
                goto exit;
            }
        }
    }
    i--;

    exit:

    board->setDomino(chips[i], firstPos, secondPos);
    chips.erase(chips.begin() + i);
}