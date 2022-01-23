#include "5990.hpp"

int main()
{
    vector<int> a = {10, 6, 5, 8}, b = {1, 3, 5, 3};
    Solution sln;
    for (auto &&i : sln.findLonely(a))
        cout << i << '\n';
    cout << '\n';
    for (auto &&i : sln.findLonely(b))
        cout << i << '\n';
    return 0;
}
