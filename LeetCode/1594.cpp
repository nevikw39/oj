#include "1594.hpp"

int main()
{
    Solution sln;
    assert(sln.maxProductPath({{-1, -2, -3}, {-2, -3, -3}, {-3, -3, -2}}) == -1);
    assert(sln.maxProductPath({{1, 3}, {0, -4}}) == 8);
    assert(sln.maxProductPath({{-1, -2, -3}, {-2, -3, -3}, {-3, -3, -2}}) == 0);
    return 0;
}
