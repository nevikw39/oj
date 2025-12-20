#include "0944.hpp"

int main()
{
    Solution sln;
    assert(sln.minDeletionSize({"cba", "daf", "ghi"}) == 1);
    assert(sln.minDeletionSize({"a", "b"}) == 0);
    assert(sln.minDeletionSize({"zyx", "wvu", "tsr"}) == 3);
    return 0;
}
