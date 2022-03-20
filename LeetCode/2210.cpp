#include "2210.hpp"

int main()
{
    vector<int> a = {2, 4, 1, 1, 6, 5}, b = {6, 6, 5, 5, 4, 1};
    Solution sln;
    cout << sln.countHillValley(a) << '\n'
         << sln.countHillValley(b) << '\n';
    return 0;
}
