#include "0645.hpp"

int main()
{
    vector<int> a{1, 2, 2, 4}, b{1, 1};
    Solution sln;
    assert(sln.findErrorNums(a) == vector<int>({2, 3}));
    assert(sln.findErrorNums(b) == vector<int>({1, 2}));
    return 0;
}
