#include "2333.hpp"

int main()
{
    Solution sln;
    assert(sln.minSumSquareDiff({1, 2, 3, 4}, {2, 10, 20, 19}, 0, 0) == 579);
    assert(sln.minSumSquareDiff({1, 4, 10, 12}, {5, 8, 6, 9}, 0, 0) == 43);
    return 0;
}
