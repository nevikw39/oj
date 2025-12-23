#include "2054.hpp"

int main()
{
    Solution sln;
    assert(sln.maxTwoEvents({{1, 3, 2}, {4, 5, 2}, {2, 4, 3}}) == 4);
    assert(sln.maxTwoEvents({{1, 3, 2}, {4, 5, 2}, {1, 5, 5}}) == 5);
    assert(sln.maxTwoEvents({{1, 5, 3}, {1, 5, 1}, {6, 6, 5}}) == 8);
    assert(sln.maxTwoEvents({{10, 83, 53}, {63, 87, 45}, {97, 100, 32}, {51, 61, 16}}) == 85);
    return 0;
}
