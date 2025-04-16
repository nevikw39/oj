#include "2537.hpp"

int main()
{
    vector<int> a{1, 1, 1, 1, 1}, b{3, 1, 4, 3, 2, 2, 4};
    Solution sln;
    assert(sln.countGood(a, 10) == 1);
    assert(sln.countGood(b, 2) == 4);
    return 0;
}
