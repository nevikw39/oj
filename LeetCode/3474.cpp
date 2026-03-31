#include "3474.hpp"

int main()
{
    Solution sln;
    assert(sln.generateString("TFTF", "ab") == "ababa");
    assert(sln.generateString("TFTF", "abc") == "");
    assert(sln.generateString("F", "d") == "a");
    assert(sln.generateString("F", "da") == "aa");
    return 0;
}
