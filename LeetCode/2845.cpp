#include "2845.hpp"

int main()
{
    vector<int> a{3,2,4}, b{3,1,9,6};
    Solution sln;
    assert(sln.countInterestingSubarrays(a, 2, 1) == 3);
    assert(sln.countInterestingSubarrays(b, 3, 0) == 2);
    return 0;
}
