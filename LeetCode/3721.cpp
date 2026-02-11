#include "3721.hpp"

int main()
{
    Solution sln;
    assert(sln.longestBalanced({2, 5, 4, 3}) == 4);
    assert(sln.longestBalanced({3, 2, 2, 5, 4}) == 5);
    assert(sln.longestBalanced({1, 2, 3, 2}) == 3);
    return 0;
}
