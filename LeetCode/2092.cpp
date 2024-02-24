#include "2092.hpp"

int main()
{
    vector<vector<int>> a{{1, 2, 5}, {2, 3, 8}, {1, 5, 10}}, b{{3, 1, 3}, {1, 2, 2}, {0, 3, 3}}, c{{3, 4, 2}, {1, 2, 1}, {2, 3, 1}};
    Solution sln;
    assert(sln.findAllPeople(6, a, 1) == vector<int>({0, 1, 2, 3, 5}));
    assert(sln.findAllPeople(4, b, 3) == vector<int>({0, 1, 3}));
    assert(sln.findAllPeople(5, c, 1) == vector<int>({0, 1, 2, 3, 4}));
    return 0;
}
