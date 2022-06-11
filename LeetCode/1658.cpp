#include "1658.hpp"

int main()
{
    vector<int> a = {1, 1, 4, 2, 3}, b = {5, 6, 7, 8, 9}, c = {3, 2, 20, 1, 1, 3}, d = {1, 1}, e = {8828,9581,49,9818,9974,9869,9991,10000,10000,10000,9999,9993,9904,8819,1231,6309};
    Solution sln;
    cout << sln.minOperations(a, 5) << '\n'
         << sln.minOperations(b, 4) << '\n'
         << sln.minOperations(c, 10) << '\n'
         << sln.minOperations(d, 3) << '\n'
         << sln.minOperations(e, 134365) << '\n';
    return 0;
}
