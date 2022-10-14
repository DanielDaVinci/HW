#include "../Headers/Board.h"

Board::Board()
{
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            matrix[i][j] = '_';
}

void Board::setDomino(Domino value, pair<int, int> firstPos, pair<int, int> secondPos)
{
    if (firstPos.first < 1 || firstPos.first > SIZE || firstPos.second < 1 || firstPos.second > SIZE ||
        secondPos.first < 1 || secondPos.first > SIZE || secondPos.second < 1 || secondPos.second > SIZE)
    {
        cerr << "Error: out of range" << endl;
        exit(1);
    }

    if (abs(firstPos.first - secondPos.first) + abs(firstPos.second - secondPos.second) != 1)
    {
        cerr << "Error: range between half of chip" << endl;
        exit(2);
    }

    if (matrix[firstPos.first - 1][firstPos.second - 1] != '_' || matrix[secondPos.first - 1][secondPos.second - 1] != '_')
    {
        cerr << "Error: place is occupied" << endl;
        exit(3);
    }

    matrix[firstPos.first - 1][firstPos.second - 1] = '0' + value.getFirst();
    matrix[secondPos.first - 1][secondPos.second - 1] = '0' + value.getSecond();

    history.Add(firstPos, secondPos);
}

int Board::getValue(pair<int, int> position)
{
    return getValue(position.first, position.second);
}

int Board::getValue(int first, int second)
{
    if (first < 1 || first > SIZE || second < 1 || second > SIZE ||
        matrix[first - 1][second - 1] == '_')
        return -1;
    else
        return matrix[first - 1][second - 1] - '0';
}

void Board::Print()
{
    cout << endl;
    cout << "   ";
    for (int j = 0; j < SIZE; j++)
        cout << " _";
    cout << endl;

    for (int i = 0; i < SIZE; i++)
    {
        cout << setw(3) << left <<  i + 1;
        for (int j = 0; j < SIZE; j++)
        {
            cout << "|" << matrix[i][j];
        }
        cout << "|" << endl;
    }

    cout << "   ";
    for (int j = 0; j < SIZE; j++)
        cout << " " << j + 1;
    cout << endl;
}

void Board::PrintDiagnostic()
{
    int firstSum = 0, secondSum = 0;
    pair<int, int> firstPos, secondPos;

    for (int i = 0; i < history.Size(); i++)
    {
        int sum = 0;
        firstPos = history[i].first;
        secondPos = history[i].second;
        sum += (matrix[firstPos.first - 1][firstPos.second- 1] == (getValue(firstPos.first + 1, firstPos.second) + '0')) +
                (matrix[firstPos.first- 1][firstPos.second- 1] == (getValue(firstPos.first - 1, firstPos.second) + '0')) +
                (matrix[firstPos.first- 1][firstPos.second- 1] == (getValue(firstPos.first, firstPos.second + 1) + '0')) +
                (matrix[firstPos.first- 1][firstPos.second- 1] == (getValue(firstPos.first, firstPos.second - 1) + '0'));
        sum += (matrix[secondPos.first- 1][secondPos.second- 1] == (getValue(secondPos.first + 1, secondPos.second) + '0')) +
               (matrix[secondPos.first- 1][secondPos.second- 1] == (getValue(secondPos.first - 1, secondPos.second) + '0')) +
               (matrix[secondPos.first- 1][secondPos.second- 1] == (getValue(secondPos.first, secondPos.second + 1) + '0')) +
               (matrix[secondPos.first- 1][secondPos.second- 1] == (getValue(secondPos.first, secondPos.second - 1) + '0'));

        if (matrix[firstPos.first - 1][firstPos.second- 1] == matrix[secondPos.first- 1][secondPos.second- 1])
            sum -= 2;

        if (i % 2 == 0)
            firstSum += (sum != 0);
        else
            secondSum += (sum != 0);
        cout << firstSum << " " << secondSum << endl;
    }

    cout << "First = " << firstSum << (firstSum > secondSum ? " - Winner!" : "") << endl;
    cout << "Second = " << secondSum << (firstSum < secondSum ? " - Winner!": "") << endl;
}