#include "3661.hpp"

int main()
{
    Solution sln;
    assert(sln.maxWalls({4}, {3}, {1, 10}) == 1);
    assert(sln.maxWalls({10, 2}, {5, 1}, {5, 2, 7}) == 3);
    assert(sln.maxWalls({1, 2}, {100, 1}, {10}) == 0);
    return 0;
}
