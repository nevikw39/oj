#include "2559.hpp"

int main()
{
    vector<string> a0{"aba", "bcb", "ece", "aa", "e"}, b0{"a", "e", "i"};
    vector<vector<int>> a1{{0, 2}, {1, 4}, {1, 1}}, b1{{0, 2}, {0, 1}, {2, 2}};
    Solution sln;
    assert(sln.vowelStrings(a0, a1) == (vector<int>{2, 3, 0}));
    assert(sln.vowelStrings(b0, b1) == (vector<int>{3, 2, 1}));
    return 0;
}
