#include "0881.hpp"

int main()
{
    vector<int> a = {1, 2}, b = {3, 2, 2, 1}, c = {3, 5, 3, 4};
    Solution sln;
    cout << sln.numRescueBoats(a, 3) << '\n'
         << sln.numRescueBoats(b, 3) << '\n'
         << sln.numRescueBoats(c, 5) << '\n';
    return 0;
}
