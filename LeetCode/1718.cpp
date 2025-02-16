#include "1718.hpp"

int main()
{
    Solution sln;
    assert(sln.constructDistancedSequence(3) == (vector<int>{3, 1, 2, 3, 2}));
    assert(sln.constructDistancedSequence(5) == (vector<int>{5, 3, 1, 4, 3, 5, 2, 4, 2}));
    return 0;
}
