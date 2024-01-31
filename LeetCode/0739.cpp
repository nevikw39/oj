#include "0739.hpp"

int main()
{
    vector<int> a{73, 74, 75, 71, 69, 72, 76, 73}, b{30, 40, 50, 60}, c{30, 60, 90}, d{89, 62, 70, 58, 47, 47, 46, 76, 100, 70};
    Solution sln;
    assert(sln.dailyTemperatures(a) == vector<int>({1, 1, 4, 2, 1, 1, 0, 0}));
    assert(sln.dailyTemperatures(b) == vector<int>({1, 1, 1, 0}));
    assert(sln.dailyTemperatures(c) == vector<int>({1, 1, 0}));
    assert(sln.dailyTemperatures(d) == vector<int>({8, 1, 5, 4, 3, 2, 1, 1, 0, 0}));
    return 0;
}
