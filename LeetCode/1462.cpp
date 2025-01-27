#include "1462.hpp"

int main()
{
    vector<vector<int>> a0{{1, 0}}, a1{{0, 1}, {1, 0}}, b0, b1{{1, 0}, {0, 1}}, c0{{1, 2}, {1, 0}, {2, 0}}, c1{{1, 0}, {1, 2}};
    Solution sln;
    assert(sln.checkIfPrerequisite(2, a0, a1) == (vector<bool>{false, true}));
    assert(sln.checkIfPrerequisite(2, b0, b1) == (vector<bool>{false, false}));
    assert(sln.checkIfPrerequisite(3, c0, c1) == (vector<bool>{true, true}));
    return 0;
}
