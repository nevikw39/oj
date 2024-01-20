#include "0907.hpp"

int main()
{
    vector<int> a{3, 1, 2, 4}, b{11, 81, 94, 43, 3};
    Solution sln;
    cout << sln.sumSubarrayMins(a) << '\n'
         << sln.sumSubarrayMins(b) << '\n';
    return 0;
}
