#include "0605.hpp"

int main()
{
    vector<int> v = {1, 0, 0, 0, 1}, vv = {1, 0, 0, 0, 0, 1}, vvv = {1, 0, 0, 0, 1, 0, 0};
    Solution sln;
    cout << sln.canPlaceFlowers(v, 1) << '\n'
         << sln.canPlaceFlowers(v, 2) << '\n'
         << sln.canPlaceFlowers(vv, 2) << '\n'
         << sln.canPlaceFlowers(vvv, 2) << '\n';
    return 0;
}
