#include "2661.hpp"

int main()
{
    vector<int> a0{1, 3, 4, 2}, b0{2, 8, 7, 4, 1, 3, 5, 6, 9};
    vector<vector<int>> a1{{1, 4}, {2, 3}}, b1{{3, 2, 5}, {1, 4, 6}, {8, 7, 9}};
    Solution sln;
    assert(sln.firstCompleteIndex(a0, a1) == 2);
    assert(sln.firstCompleteIndex(b0, b1) == 3);
    return 0;
}
