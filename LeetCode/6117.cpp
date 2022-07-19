#include "6117.hpp"

int main()
{
    vector<int> a0{10, 20}, a1{2, 17, 18, 19}, b0{20, 30, 10}, b1{19, 13, 26, 4, 25, 11, 21}, c0{3}, c1{2, 4}, d0{3}, d1{2};
    Solution sln;
    cout << sln.latestTimeCatchTheBus(a0, a1, 2) << '\n'
         << sln.latestTimeCatchTheBus(b0, b1, 2) << '\n'
         << sln.latestTimeCatchTheBus(c0, c1, 2) << '\n'
         << sln.latestTimeCatchTheBus(d0, d1, 1) << '\n';
    return 0;
}
