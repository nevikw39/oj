#include "2022.hpp"

int main()
{
    vector<int> a = {1, 2, 3, 4}, b = {1, 2, 3}, c = {1, 2}, d = {3};
    Solution sln;
    for (const auto &i : sln.construct2DArray(a, 2, 2))
    {
        for (const int &j : i)
            cout << j << ' ';
        cout << '\n';
    }
    for (const auto &i : sln.construct2DArray(b, 1, 3))
    {
        for (const int &j : i)
            cout << j << ' ';
        cout << '\n';
    }
    for (const auto &i : sln.construct2DArray(c, 1, 1))
    {
        for (const int &j : i)
            cout << j << ' ';
        cout << '\n';
    }
    for (const auto &i : sln.construct2DArray(d, 1, 2))
    {
        for (const int &j : i)
            cout << j << ' ';
        cout << '\n';
    }
    return 0;
}
