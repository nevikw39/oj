#include "5894.hpp"

int main()
{
    vector<int> a1 = {1, 1, 3, 2}, a2 = {2, 3}, a3 = {3}, b1 = {3, 1}, b2 = {2, 3}, b3 = {1, 2}, c1 = {1, 2, 2}, c2 = {4, 3, 3}, c3 = {5};
    Solution sln;
    for (const int &i : sln.twoOutOfThree(a1, a2, a3))
        cout << i << ' ';
    cout << '\n';
    for (const int &i : sln.twoOutOfThree(b1, b2, b3))
        cout << i << ' ';
    cout << '\n';
    for (const int &i : sln.twoOutOfThree(c1, c2, c3))
        cout << i << ' ';
    cout << '\n';
    return 0;
}
