#include "1266.hpp"

int main()
{
    Solution sln;
    assert(sln.minTimeToVisitAllPoints({{1, 1}, {3, 4}, {-1, 0}}) == 7);
    assert(sln.minTimeToVisitAllPoints({{3, 2}, {-2, 2}}) == 5);
    return 0;
}
