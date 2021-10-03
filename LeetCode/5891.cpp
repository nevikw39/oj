#include "5891.hpp"

int main()
{
    vector<int> a = {3, 2, 4, 3}, b = {1, 5, 6}, c = {1, 2, 3, 4}, d = {1};
    Solution sln;
    for (const int &i : sln.missingRolls(a, 4, 2))
        cout << i << ' ';
    cout << '\n';
    for (const int &i : sln.missingRolls(b, 3, 4))
        cout << i << ' ';
    cout << '\n';
    for (const int &i : sln.missingRolls(c, 6, 4))
        cout << i << ' ';
    cout << '\n';
    for (const int &i : sln.missingRolls(d, 3, 1))
        cout << i << ' ';
    cout << '\n';
    return 0;
}
