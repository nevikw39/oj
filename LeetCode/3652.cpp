#include "3652.hpp"

int main()
{
    Solution sln;
    assert(sln.maxProfit({4, 2, 8}, {-1, 0, 1}, 2) == 10);
    assert(sln.maxProfit({5, 4, 3}, {1, 1, 0}, 2) == 9);
    return 0;
}
