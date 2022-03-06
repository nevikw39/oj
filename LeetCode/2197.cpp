#include "2197.hpp"

int main()
{
    vector<int> a = {6, 4, 3, 2, 7, 6, 2}, b = {2, 2, 1, 1, 3, 3, 3}, c = {287, 41, 49, 287, 899, 23, 23, 20677, 5, 825};
    Solution sln;
    for (auto &&i : sln.replaceNonCoprimes(a))
        cout << i << '\n';
    cout << '\n';
    for (auto &&i : sln.replaceNonCoprimes(b))
        cout << i << '\n';
    cout << '\n';
    for (auto &&i : sln.replaceNonCoprimes(c))
        cout << i << '\n';
    return 0;
}
