#include "1671.hpp"

int main()
{
    vector<int> a{1, 3, 1}, b{2, 1, 1, 5, 6, 2, 3, 1};
    Solution sln;
    assert(sln.minimumMountainRemovals(a) == 0);
    assert(sln.minimumMountainRemovals(b) == 3);
    return 0;
}
