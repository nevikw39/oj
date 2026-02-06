#include "3379.hpp"

int main()
{
    Solution sln;
    assert((sln.constructTransformedArray({3, -2, 1, 1}) == vector{1, 1, 1, 3}));
    assert((sln.constructTransformedArray({-1, 4, -1}) == vector{-1, -1, 4}));
    return 0;
}
