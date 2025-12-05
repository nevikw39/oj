#include "3432.hpp"

int main()
{
    Solution sln;
    assert(sln.countPartitions({10, 10, 3, 7, 6}) == 4);
    assert(sln.countPartitions({1, 2, 2}) == 0);
    assert(sln.countPartitions({2, 4, 6, 8}) == 3);
    return 0;
}
