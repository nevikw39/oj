#include "3510.hpp"

int main()
{
    Solution sln;
    assert(sln.minimumPairRemoval({5, 2, 3, 1}) == 2);
    assert(sln.minimumPairRemoval({1, 2, 2}) == 0);
    assert(sln.minimumPairRemoval({2, 2, -1, 3, -2, 2, 1, 1, 1, 0, -1}) == 9);
    return 0;
}
