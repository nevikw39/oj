#include "3578.hpp"

int main()
{
    Solution sln;
    assert(sln.countPartitions({9, 4, 1, 3, 7}, 4) == 6);
    assert(sln.countPartitions({3, 3, 4}, 0) == 2);
    return 0;
}
