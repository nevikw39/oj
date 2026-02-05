#include "3640.hpp"

int main()
{
    Solution sln;
    assert(sln.maxSumTrionic({0, -2, -1, -3, 0, 2, -1}) == -4);
    assert(sln.maxSumTrionic({1, 4, 2, 7}) == 14);
    return 0;
}
