#include "3637.hpp"

int main()
{
    Solution sln;
    assert(sln.isTrionic({1, 3, 5, 4, 2, 6}) == true);
    assert(sln.isTrionic({2, 1, 3}) == false);
    assert(sln.isTrionic({7, 6, 4, 4}) == false);
    assert(sln.isTrionic({7, 8, 9, 6, 6, 1, 1, 7}) == false);
    assert(sln.isTrionic({1, 6, 6, 3, 7}) == false);
    return 0;
}
