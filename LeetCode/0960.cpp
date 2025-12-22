#include "0960.hpp"

int main()
{
    Solution sln;
    assert(sln.minDeletionSize({"babca", "bbazb"}) == 3);
    assert(sln.minDeletionSize({"edcba"}) == 4);
    assert(sln.minDeletionSize({"ghi", "def", "abc"}) == 0);
    return 0;
}
