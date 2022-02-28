#include "0228.hpp"

int main()
{
    vector<int> a = {0, 1, 2, 4, 5, 7}, b = {0, 2, 3, 4, 6, 8, 9};
    Solution sln;
    for (auto &&i : sln.summaryRanges(a))
        cout << i << '\n';
    cout << '\n';
    for (auto &&i : sln.summaryRanges(b))
        cout << i << '\n';
    return 0;
}
