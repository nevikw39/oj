#include "0134.hpp"

int main()
{
    vector<int> a0 = {1, 2, 3, 4, 5}, a1 = {3, 4, 5, 1, 2}, b0 = {2, 3, 4}, b1 = {3, 4, 3};
    Solution sln;
    cout << sln.canCompleteCircuit(a0, a1) << '\n'
         << sln.canCompleteCircuit(b0, b1) << '\n';
    return 0;
}
