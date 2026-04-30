#include "3742.hpp"

int main()
{
    Solution sln;
    assert(sln.maxPathScore({{0, 1}, {2, 0}}, 1) == 2);
    assert(sln.maxPathScore({{0, 1}, {1, 2}}, 1) == -1);
    return 0;
}
