#include "1726.hpp"

int main()
{
    vector<int> a{2, 3, 4, 6}, b{1, 2, 4, 5, 10};
    Solution sln;
    assert(sln.tupleSameProduct(a) == 8);
    assert(sln.tupleSameProduct(b) == 16);
    return 0;
}
