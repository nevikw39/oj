#include "5985.hpp"

int main()
{
    vector<int> a = {9, 12, 5, 10, 14, 3, 10}, b = {-3, 4, 3, 2};
    Solution sln;
    sln.pivotArray(a, 10);
    for (const int &i : a)
        cout << i << '\n';
    cout << '\n';
    sln.pivotArray(b, 2);
    for (const int &i : b)
        cout << i << '\n';
    return 0;
}
