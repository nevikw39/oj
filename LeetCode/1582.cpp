#include "1582.hpp"

int main()
{
    Solution sln;
    assert(sln.numSpecial({{1, 0, 0}, {0, 0, 1}, {1, 0, 0}}) == 1);
    assert(sln.numSpecial({{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}) == 3);
    return 0;
}
