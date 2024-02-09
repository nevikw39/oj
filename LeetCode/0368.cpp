#include "0368.hpp"

int main()
{
    vector<int> a{1, 2, 3}, b{1, 2, 4, 8}, c{2, 4}, d{3, 4, 16, 8};
    Solution sln;
    assert(sln.largestDivisibleSubset(a) == vector<int>({2, 1}));
    assert(sln.largestDivisibleSubset(b) == vector<int>({8, 4, 2, 1}));
    assert(sln.largestDivisibleSubset(c) == vector<int>({4, 2}));
    assert(sln.largestDivisibleSubset(d) == vector<int>({16, 8, 4}));
    return 0;
}
