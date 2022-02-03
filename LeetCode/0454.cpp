#include "0454.hpp"

int main()
{
    vector<int> a1 = {1, 2}, a2 = {-2, -1}, a3 = {-1, 2}, a4 = {0, 2}, b = {0};
    Solution sln;
    cout << sln.fourSumCount(a1, a2, a3, a4) << '\n'
         << sln.fourSumCount(b, b, b, b) << '\n';
    return 0;
}
