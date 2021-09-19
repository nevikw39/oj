#include "2007.hpp"

int main()
{
    vector<int> a = {1, 3, 4, 2, 6, 8}, b = {6, 3, 0, 1}, c = {1};
    Solution sln;
    for (const int &i : sln.findOriginalArray(a))
        cout << i << '\n';
    cout << '\n';
    for (const int &i : sln.findOriginalArray(b))
        cout << i << '\n';
    cout << '\n';
    for (const int &i : sln.findOriginalArray(c))
        cout << i << '\n';
    cout << '\n';
    return 0;
}
