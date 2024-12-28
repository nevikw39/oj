#include "0689.hpp"

int main()
{
    vector<int> a = {1, 2, 1, 2, 6, 7, 5, 1}, b = {1, 2, 1, 2, 1, 2, 1, 2, 1};
    Solution sln;
    assert(sln.maxSumOfThreeSubarrays(a, 2) == vector<int>({0, 3, 5}));
    assert(sln.maxSumOfThreeSubarrays(b, 2) == vector<int>({0, 2, 4}));
    return 0;
}
