#include "0078.hpp"

int main()
{
    vector<int> a = {1, 2, 3}, b = {0};
    Solution sln;
    for (auto &&i : sln.subsets(a))
    {
        for (auto &&j : i)
            cout << j << ' ';
        cout << '\n';
    }
    cout << '\n';
    for (auto &&i : sln.subsets(b))
    {
        for (auto &&j : i)
            cout << j << ' ';
        cout << '\n';
    }
    return 0;
}
