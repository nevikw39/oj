#include "2799.hpp"

int main()
{
    vector<int> a{1, 3, 1, 2, 2}, b{5, 5, 5, 5};
    Solution sln;
    assert(sln.countCompleteSubarrays(a) == 4);
    assert(sln.countCompleteSubarrays(b) == 10);
    return 0;
}
