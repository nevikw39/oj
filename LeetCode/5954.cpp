#include "5954.hpp"

int main()
{
    vector<int> a = {2, 2, 3, 3}, b = {2, 2, 3, 3}, c = {5}, d = {1, 2, 4, 4, 5}, e = {2, 2, 5, 2, 2}, f = {1, 2}, g = {2, 2, 3, 3};
    Solution sln;
    cout << sln.minimumRefill(a, 5, 5) << '\n'
         << sln.minimumRefill(b, 3, 4) << '\n'
         << sln.minimumRefill(c, 10, 8) << '\n'
         << sln.minimumRefill(d, 6, 5) << '\n'
         << sln.minimumRefill(e, 5, 5) << '\n'
         << sln.minimumRefill(f, 2, 2) << '\n'
         << sln.minimumRefill(g, 5, 5) << '\n';
    return 0;
}
