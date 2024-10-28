#include "2501.hpp"

int main()
{
    vector<int> a{4, 3, 6, 16, 8, 2}, b{2, 3, 5, 6, 7}, c{4, 16, 256, 65536};
    Solution sln;
    assert(sln.longestSquareStreak(a) == 3);
    assert(sln.longestSquareStreak(b) == -1);
    assert(sln.longestSquareStreak(c) == 4);
    return 0;
}
