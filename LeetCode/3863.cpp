#include "3863.hpp"

int main()
{
    Solution sln;
    assert(sln.minOperations("dog") == 1);
    assert(sln.minOperations("card") == 2);
    assert(sln.minOperations("gf") == -1);
    return 0;
}
