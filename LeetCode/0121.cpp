#include "0121.hpp"

int main()
{
    vector<int> a = {7, 1, 5, 3, 6, 4}, b = {7, 6, 4, 3, 1};
    Solution sln;
    cout << sln.maxProfit(a) << '\n'
         << sln.maxProfit(b) << '\n';
    return 0;
}
