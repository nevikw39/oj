#include "2601.hpp"

int main()
{
    vector<int> a{4, 9, 6, 10}, b{6, 8, 11, 12}, c{5, 8, 3};
    Solution sln;
    assert(sln.primeSubOperation(a));
    assert(sln.primeSubOperation(b));
    assert(!sln.primeSubOperation(c));
    return 0;
}
