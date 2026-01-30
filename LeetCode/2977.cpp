#include "2977.hpp"

int main()
{
    Solution sln;
    assert(sln.minimumCost("abcdefgh", "acdeeghh", {"bcd", "fgh", "thh"}, {"cde", "thh", "ghh"}, {1, 3, 5}) == 9);
    assert(sln.minimumCost("abcdefgh", "addddddd", {"bcd", "fdefgh"}, {"ddd", "ddddd"}, {100, 1578}) == -1);
    return 0;
}
