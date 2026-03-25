#include "3546.hpp"

int main()
{
    Solution sln;
    assert(sln.canPartitionGrid({{1, 4}, {2, 3}}) == true);
    assert(sln.canPartitionGrid({{1, 3}, {2, 4}}) == false);
    return 0;
}
