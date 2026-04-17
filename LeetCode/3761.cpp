#include "3761.hpp"

int main()
{
    Solution sln;
    assert(sln.minMirrorPairDistance({12, 21, 45, 33, 54}) == 1);
    assert(sln.minMirrorPairDistance({120, 21}) == 1);
    assert(sln.minMirrorPairDistance({21, 120}) == -1);
    return 0;
}
