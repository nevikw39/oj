#include "0189.hpp"

int main()
{
    vector<int> a = {1, 2, 3, 4, 5, 6, 7}, b = {-1, -100, 3, 99};
    Solution sln;
    sln.rotate(a, 3);
    sln.rotate(b, 2);
    for (const auto &i : a)
        cout << i << '\n';
    cout << '\n';
    for (const auto &i : b)
        cout << i << '\n';
    return 0;
}
