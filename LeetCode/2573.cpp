#include "2573.hpp"

int main()
{
    Solution sln;
    assert(sln.findTheString({{4, 0, 2, 0}, {0, 3, 0, 1}, {2, 0, 2, 0}, {0, 1, 0, 1}}) == "abab");
    assert(sln.findTheString({{4, 3, 2, 1}, {3, 3, 2, 1}, {2, 2, 2, 1}, {1, 1, 1, 1}}) == "aaaa");
    assert(sln.findTheString({{4, 3, 2, 1}, {3, 3, 2, 1}, {2, 2, 2, 1}, {1, 1, 1, 3}}) == "");
    return 0;
}
