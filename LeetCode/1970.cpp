#include "1970.hpp"

int main()
{
    Solution sln;
    assert(sln.latestDayToCross(2, 2, {{1, 1}, {2, 1}, {1, 2}, {2, 2}}) == 2);
    assert(sln.latestDayToCross(2, 2, {{1, 1}, {1, 2}, {2, 1}, {2, 2}}) == 1);
    assert(sln.latestDayToCross(3, 3, {{1, 2}, {2, 1}, {3, 3}, {2, 2}, {1, 1}, {1, 3}, {2, 3}, {3, 2}, {3, 1}}) == 3);
    return 0;
}
