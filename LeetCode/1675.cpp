#include "1675.hpp"

int main()
{
    vector<int> a = {1, 2, 3, 4}, b = {4, 1, 5, 20, 3}, c = {2, 10, 8};
    Solution sln;
    cout << sln.minimumDeviation(a) << '\n'
         << sln.minimumDeviation(b) << '\n'
         << sln.minimumDeviation(c) << '\n';
    return 0;
}
