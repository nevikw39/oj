#include "3551.hpp"

int main()
{
    Solution sln;
    assert(sln.minSwaps({37, 100}) == 1);
    assert(sln.minSwaps({22, 14, 33, 7}) == 0);
    assert(sln.minSwaps({18, 43, 34, 16}) == 2);
    return 0;
}
