#include "2121.hpp"

int main()
{
    vector<int> a = {2, 1, 3, 1, 2, 3, 3}, b = {10, 5, 10, 10};
    Solution sln;
    for (auto &&i : sln.getDistances(a))
        cout << i << '\n';
    cout << '\n';
    for (auto &&i : sln.getDistances(b))
        cout << i << '\n';
    cout << '\n';
    return 0;
}
