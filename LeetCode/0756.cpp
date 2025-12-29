#include "0756.hpp"

int main()
{
    Solution sln;
    assert(sln.pyramidTransition("BCD", {"BCC", "CDE", "CEA", "FFF"}) == true);
    assert(sln.pyramidTransition("AAA", {"AAB", "AAC", "BCD", "BBE", "DEF"}) == false);
    assert(sln.pyramidTransition("ABCD", {"ABC", "BCA", "CDA", "ABD", "BCE", "CDF", "DEA", "EFF", "AFF"}) == true);
    return 0;
}
