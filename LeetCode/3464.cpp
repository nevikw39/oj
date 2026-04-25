#include "3464.hpp"

int main()
{
    Solution sln;
    assert(sln.maxDistance(2, {{0, 2}, {2, 0}, {2, 2}, {0, 0}}, 4) == 2);
    assert(sln.maxDistance(2, {{0, 0}, {1, 2}, {2, 0}, {2, 2}, {2, 1}}, 4) == 1);
    assert(sln.maxDistance(2, {{0, 0}, {0, 1}, {0, 2}, {1, 2}, {2, 0}, {2, 2}, {2, 1}}, 5) == 1);
    return 0;
}
