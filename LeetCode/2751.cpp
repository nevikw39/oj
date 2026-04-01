#include "2751.hpp"

int main()
{
    Solution sln;
    assert(sln.survivedRobotsHealths({5, 4, 3, 2, 1}, {2, 17, 9, 15, 10}, "RRRRR") == vector({2, 17, 9, 15, 10}));
    assert(sln.survivedRobotsHealths({3, 5, 2, 6}, {10, 10, 15, 12}, "RLRL") == vector({14}));
    assert(sln.survivedRobotsHealths({1, 2, 5, 6}, {10, 10, 11, 11}, "RLRL") == vector<int>());
    return 0;
}
