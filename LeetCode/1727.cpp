#include "1727.hpp"

int main()
{
    Solution sln;
    assert(sln.largestSubmatrix({{0, 0, 1}, {1, 1, 1}, {1, 0, 1}}) == 4);
    assert(sln.largestSubmatrix({{1, 0, 1, 0, 1}}) == 3);
    assert(sln.largestSubmatrix({{1, 1, 0}, {1, 0, 1}}) == 2);
    return 0;
}
