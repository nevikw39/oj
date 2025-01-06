#include "1769.hpp"

int main()
{
    string a = "110", b = "001011";
    Solution sln;
    assert(sln.minOperations(a) == vector<int>({1, 1, 3}));
    assert(sln.minOperations(b) == vector<int>({11, 8, 5, 4, 3, 4}));
    return 0;
}
