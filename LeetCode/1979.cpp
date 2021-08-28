#include "1979.hpp"

int main()
{
    vector<int> a = {2, 5, 6, 9, 10}, b = {7, 5, 6, 8, 3}, c = {3, 3};
    Solution sln;
    cout << sln.findGCD(a) << '\n'
         << sln.findGCD(b) << '\n'
         << sln.findGCD(c) << '\n';
    return 0;
}
