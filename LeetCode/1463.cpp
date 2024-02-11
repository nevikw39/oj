#include "1463.hpp"

int main()
{
    vector<vector<int>> a{{3, 1, 1}, {2, 5, 1}, {1, 5, 5}, {2, 1, 1}}, b{{1, 0, 0, 0, 0, 0, 1}, {2, 0, 0, 0, 0, 3, 0}, {2, 0, 9, 0, 0, 0, 0}, {0, 3, 0, 5, 4, 0, 0}, {1, 0, 2, 3, 0, 0, 6}};
    Solution sln;
    cout << sln.cherryPickup(a) << '\n'
         << sln.cherryPickup(b) << '\n';
    return 0;
}
