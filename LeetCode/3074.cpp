#include "3074.hpp"

int main()
{
    Solution sln;
    assert(sln.minimumBoxes({1, 3, 2}, {4, 3, 1, 5, 2}) == 2);
    assert(sln.minimumBoxes({5, 5, 5}, {2, 4, 2, 7}) == 4);
    return 0;
}
