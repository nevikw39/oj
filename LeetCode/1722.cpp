#include "1722.hpp"

int main()
{
    Solution sln;
    assert(sln.minimumHammingDistance({1, 2, 3, 4}, {2, 1, 4, 5}, {{0, 1}, {2, 3}}) == 1);
    assert(sln.minimumHammingDistance({1, 2, 3, 4}, {1, 3, 2, 4}, {}) == 2);
    assert(sln.minimumHammingDistance({5, 1, 2, 4, 3}, {1, 5, 4, 2, 3}, {{0, 4}, {4, 2}, {1, 3}, {1, 4}}) == 0);
    return 0;
}
