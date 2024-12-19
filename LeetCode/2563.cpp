#include "2563.hpp"

int main()
{
    vector<int> a{0, 1, 7, 4, 4, 5}, b{1, 7, 9, 2, 5};
    Solution sln;
    assert(sln.countFairPairs(a, 3, 6) == 6);
    assert(sln.countFairPairs(b, 11, 11) == 1);
    return 0;
}
