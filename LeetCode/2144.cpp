#include "2144.hpp"

int main()
{
    vector<int> a = {1, 2, 3}, b = {6, 5, 7, 9, 2, 2}, c = {5, 5};
    Solution sln;
    cout << sln.minimumCost(a) << '\n'
         << sln.minimumCost(b) << '\n'
         << sln.minimumCost(c) << '\n';
    return 0;
}
