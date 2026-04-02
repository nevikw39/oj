#include "3418.hpp"

int main()
{
    Solution sln;
    assert(sln.maximumAmount({{0, 1, -1}, {1, -2, 3}, {2, -3, 4}}) == 8);
    assert(sln.maximumAmount({{10, 10, 10}, {10, 10, 10}}) == 40);
    assert(sln.maximumAmount({{-3, -10, 11, -16}, {-13, 19, -2, 2}, {-16, -11, 5, 13}, {-5, 13, -20, -6}}) == 32);
    return 0;
}
