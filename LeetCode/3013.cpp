#include "3013.hpp"

int main()
{
    Solution sln;
    assert(sln.minimumCost({1, 3, 2, 6, 4, 2}, 3, 3) == 5);
    assert(sln.minimumCost({10, 1, 2, 2, 2, 1}, 4, 3) == 15);
    assert(sln.minimumCost({10, 8, 18, 9}, 3, 1) == 36);
    assert(sln.minimumCost({1, 6, 4, 6, 2, 9, 11}, 4, 3) == 13);
    return 0;
}
