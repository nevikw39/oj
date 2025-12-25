#include "3075.hpp"

int main()
{
    Solution sln;
    assert(sln.maximumHappinessSum({1, 2, 3}, 2) == 4);
    assert(sln.maximumHappinessSum({1, 1, 1, 1}, 2) == 1);
    assert(sln.maximumHappinessSum({2, 3, 4, 5}, 1) == 1);
    return 0;
}
