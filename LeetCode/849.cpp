#include "849.hpp"

int main()
{
    vector<int> a = {1, 0, 0, 0, 1, 0, 1}, b = {1, 0, 0, 0}, c = {0, 1};
    Solution sln;
    cout << sln.maxDistToClosest(a) << '\n'
         << sln.maxDistToClosest(b) << '\n'
         << sln.maxDistToClosest(c) << '\n';
    return 0;
}
