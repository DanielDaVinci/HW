#include "../Headers/History.h"

History::History()
{

}

int History::Size()
{
    return list.size();
}

void History::Add(pair<int, int> first, pair<int, int> second)
{
    list.push_back(make_pair(first, second));
}

pair<pair<int, int>, pair<int, int>> History::getLastMove()
{
    return (*this)[Size() - 1];
}

pair<pair<int, int>, pair<int, int>> History::operator [] (int index) const
{
    return list[index];
}