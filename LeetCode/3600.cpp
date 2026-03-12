#include "3600.hpp"

int main()
{
    Solution sln;
    assert(sln.maxStability(3, {{0, 1, 2, 1}, {1, 2, 3, 0}}, 1) == 2);
    assert(sln.maxStability(3, {{0, 1, 4, 0}, {1, 2, 3, 0}, {0, 2, 1, 0}}, 2) == 6);
    assert(sln.maxStability(3, {{0, 1, 1, 1}, {1, 2, 1, 1}, {2, 0, 1, 1}}, 0) == -1);
    return 0;
}
