#include "3129.hpp"

int main()
{
    Solution sln;
    assert(sln.numberOfStableArrays(1, 1, 2) == 2);
    assert(sln.numberOfStableArrays(1, 2, 1) == 1);
    assert(sln.numberOfStableArrays(3, 3, 2) == 1);
    return 0;
}
