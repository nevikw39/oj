#include "5991.hpp"

int main()
{
    vector<int> a = {3, 1, -2, -5, 2, -4}, b = {-1, 1};
    Solution sln;
    for (auto &&i : sln.rearrangeArray(a))
        cout << i << '\n';
    cout << '\n';
    for (auto &&i : sln.rearrangeArray(b))
        cout << i << '\n';
    return 0;
}
