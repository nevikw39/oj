#include "2200.hpp"

int main()
{
    vector<int> a = {3, 4, 9, 1, 3, 9, 5}, b = {2, 2, 2, 2, 2};
    Solution sln;
    for (auto &&i : sln.findKDistantIndices(a, 9, 1))
        cout << i << '\n';
    cout << '\n';
    for (auto &&i : sln.findKDistantIndices(b, 2, 2))
        cout << i << '\n';
    return 0;
}
