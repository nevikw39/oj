#include "0004.hpp"

int main()
{
    vector<int> a1 = {1, 3}, a2 = {2}, b1 = {1, 2}, b2 = {3, 4}, c1 = {0, 0}, c2 = {0, 0}, d1, d2 = {1}, e1 = {2}, e2;
    Solution sln;
    cout << sln.findMedianSortedArrays(a1, a2) << '\n'
         << sln.findMedianSortedArrays(b1, b2) << '\n'
         << sln.findMedianSortedArrays(c1, c2) << '\n'
         << sln.findMedianSortedArrays(d1, d2) << '\n'
         << sln.findMedianSortedArrays(e1, e2) << '\n';
    return 0;
}
