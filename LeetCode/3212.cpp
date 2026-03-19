#include "3212.hpp"

int main()
{
    Solution sln;
    assert(sln.numberOfSubmatrices({{'X', 'Y', '.'}, {'Y', '.', '.'}}) == 3);
    assert(sln.numberOfSubmatrices({{'X', 'X'}, {'X', 'Y'}}) == 0);
    return 0;
}
