#include "3070.hpp"

int main()
{
    Solution sln;
    assert(sln.countSubmatrices({{7, 6, 3}, {6, 6, 1}}, 18) == 4);
    assert(sln.countSubmatrices({{7, 2, 9}, {1, 5, 0}, {2, 6, 6}}, 20) == 6);
    return 0;
}
