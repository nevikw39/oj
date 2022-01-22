#include "2145.hpp"

int main()
{
    vector<int> a = {1, -3, 4}, b = {3, -4, 5, 1, -2}, c = {4, -7, 2}, d = {-40}, e = {83702, -5216};
    Solution sln;
    cout << sln.numberOfArrays(a, 1, 6) << '\n'
         << sln.numberOfArrays(b, -4, 5) << '\n'
         << sln.numberOfArrays(c, 3, 6) << '\n'
         << sln.numberOfArrays(d, -46, 53) << '\n'
         << sln.numberOfArrays(e, -82788, 14602) << '\n';
    return 0;
}
