#include "2946.hpp"

int main()
{
    Solution sln;
    assert(sln.areSimilar({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, 4) == false);
    assert(sln.areSimilar({{1, 2, 1, 2}, {5, 5, 5, 5}, {6, 3, 6, 3}}, 2) == true);
    assert(sln.areSimilar({{2, 2}, {2, 2}}, 3) == true);
    return 0;
}
