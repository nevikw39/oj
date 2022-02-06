#include "0080.hpp"

int main()
{
    vector<int> a = {1, 1, 1, 2, 2, 3}, b = {0, 0, 1, 1, 1, 1, 2, 3, 3};
    Solution sln;
    for (int i = 0, k = sln.removeDuplicates(a); i < k; i++)
        cout << a[i] << '\n';
    cout << '\n';
    for (int i = 0, k = sln.removeDuplicates(b); i < k; i++)
        cout << b[i] << '\n';
    return 0;
}
