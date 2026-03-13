#include "3296.hpp"

int main()
{
    Solution sln;
    assert(sln.minNumberOfSeconds(4, {2, 1, 1}) == 3);
    assert(sln.minNumberOfSeconds(10, {3,2,2,4}) == 12);
    assert(sln.minNumberOfSeconds(5, {1}) == 15);
    return 0;
}
