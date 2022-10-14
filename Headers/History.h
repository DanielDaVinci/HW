#ifndef PRACTICA_HISTORY_H
#define PRACTICA_HISTORY_H

#include <vector>
#include <tuple>

using namespace std;

class History
{
private:
    vector<pair<pair<int, int>, pair<int, int>>> list;
public:
    History();

    int Size();
    void Add(pair<int, int>, pair<int, int>);
    pair<pair<int, int>, pair<int, int>> getLastMove();

    pair<pair<int, int>, pair<int, int>> operator [] (int) const;
};

#endif
