#include "2164.hpp"

int main()
{
    vector<int> a = {4, 1, 2, 3}, b = {2, 1};
    Solution sln;
    for (auto &&i : sln.sortEvenOdd(a))
        cout << i << '\n';
    cout << '\n';
    for (auto &&i : sln.sortEvenOdd(b))
        cout << i << '\n';
    return 0;
}
