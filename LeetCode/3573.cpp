#include "3573.hpp"

int main()
{
    Solution sln;
    assert(sln.maximumProfit({1, 7, 9, 8, 2}, 2) == 14);
    assert(sln.maximumProfit({12, 16, 19, 19, 8, 1, 19, 13, 9}, 3) == 36);
    return 0;
}
