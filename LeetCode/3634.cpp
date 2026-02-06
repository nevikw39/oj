#include "3634.hpp"

int main()
{
    vector a{2, 1, 5}, b{1, 6, 2, 9}, c{4, 6};
    Solution sln;
    assert(sln.minRemoval(a, 2) == 1);
    assert(sln.minRemoval(b, 3) == 2);
    assert(sln.minRemoval(c, 2) == 01);
    return 0;
}
