#include "2906.hpp"

int main()
{
    Solution sln;
    assert(sln.constructProductMatrix({{1, 2}, {3, 4}}) == vector<vector<int>>({{24, 12}, {8, 6}}));
    assert(sln.constructProductMatrix({{12345}, {2}, {1}}) == vector<vector<int>>({{2}, {0}, {0}}));
    return 0;
}
