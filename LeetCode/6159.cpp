#include "6159.hpp"

int main()
{
    vector<int> a0{1, 2, 5, 6, 1}, a1{0, 3, 2, 4, 1}, b0{3, 2, 11, 1}, b1{3, 2, 1, 0};
    Solution sln;
    for (auto &i : sln.maximumSegmentSum(a0, a1))
        cout << i << ' ';
    cout << '\n';
    for (auto &i : sln.maximumSegmentSum(b0, b1))
        cout << i << ' ';
    cout << '\n';
    return 0;
}
