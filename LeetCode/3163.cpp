#include "3163.hpp"

int main()
{
    Solution sln;
    assert(sln.compressedString("abcde") == "1a1b1c1d1e");
    assert(sln.compressedString("aaaaaaaaaaaaaabb") == "9a5a2b");
    return 0;
}
