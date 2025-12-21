#include "0955.hpp"

int main()
{
    Solution sln;
    assert(sln.minDeletionSize({"ca", "bb", "ac"}) == 1);
    assert(sln.minDeletionSize({"xc", "yb", "za"}) == 0);
    assert(sln.minDeletionSize({"zyx", "wvu", "tsr"}) == 3);
    return 0;
}
