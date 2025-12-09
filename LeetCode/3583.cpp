#include "3583.hpp"

int main()
{
    Solution sln;
    assert(sln.specialTriplets({6, 3, 6}) == 1);
    assert(sln.specialTriplets({0, 1, 0, 0}) == 1);
    assert(sln.specialTriplets({8, 4, 2, 8, 4}) == 2);
    assert(sln.specialTriplets({36, 18, 36, 33, 10, 20}) == 1);
    return 0;
}
