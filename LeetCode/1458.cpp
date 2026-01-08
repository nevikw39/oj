#include "1458.hpp"

int main()
{
    Solution sln;
    assert(sln.maxDotProduct({2, 1, -2, 5}, {3, 0, -6}) == 18);
    assert(sln.maxDotProduct({3, -2}, {2, -6, 7}) == 21);
    assert(sln.maxDotProduct({-1, -1}, {1, 1}) == -1);
    return 0;
}
