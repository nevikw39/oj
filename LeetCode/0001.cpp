#include "0001.hpp"

int main()
{
    vector<int> a = {2, 7, 11, 15}, b = {3, 2, 4}, c = {3, 3};
    Solution sln;
    for (const int &i : sln.twoSum(a, 9))
        cout << i << ' ';
    cout << '\n';
    for (const int &i : sln.twoSum(b, 6))
        cout << i << ' ';
    cout << '\n';
    for (const int &i : sln.twoSum(c, 6))
        cout << i << ' ';
    cout << '\n';
    return 0;
}
