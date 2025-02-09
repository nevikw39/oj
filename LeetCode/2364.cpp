#include "2364.hpp"

int main()
{
    vector<int> a{4, 1, 3, 3}, b{1, 2, 3, 4, 5};
    Solution sln;
    assert(sln.countBadPairs(a) == 5);
    assert(sln.countBadPairs(b) == 0);
    return 0;
}
