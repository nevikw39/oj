#include "3562.hpp"

int main()
{
    Solution sln;
    assert(sln.maxProfit(2, {1, 2}, {4, 3}, {{1, 2}}, 3) == 5);
    assert(sln.maxProfit(2, {3, 4}, {5, 8}, {{1, 2}}, 4) == 4);
    assert(sln.maxProfit(3, {4, 6, 8}, {7, 9, 11}, {{1, 2}, {1, 3}}, 10) == 10);
    assert(sln.maxProfit(3, {5, 2, 3}, {8, 5, 6}, {{1, 2}, {1, 3}}, 7) == 12);
    assert(sln.maxProfit(2, {33, 13}, {34, 15}, {{1, 2}}, 20) == 2);
    return 0;
}
