#include "0349.hpp"

int main()
{
    vector<int> a0{1, 2, 2, 1}, a1{2, 2}, b0{4, 9, 5}, b1{9, 4, 9, 8, 4};
    Solution sln;
    assert(sln.intersection(a0, a1) == vector<int>({2}));
    assert(sln.intersection(b0, b1) == vector<int>({4, 9}));
    return 0;
}
