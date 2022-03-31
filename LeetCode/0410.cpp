#include "0410.hpp"

int main()
{
    vector<int> a = {7, 2, 5, 10, 8}, b = {1, 2, 3, 4, 5}, c = {1, 4, 4};
    Solution sln;
    cout << sln.splitArray(a, 2) << '\n'
         << sln.splitArray(b, 2) << '\n'
         << sln.splitArray(c, 3) << '\n';
    return 0;
}
