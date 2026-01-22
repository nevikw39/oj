#include "3507.hpp"

int main()
{
    Solution sln;
    assert(sln.minimumPairRemoval({5, 2, 3, 1}) == 2);
    assert(sln.minimumPairRemoval({1, 2, 2}) == 0);
    return 0;
}
