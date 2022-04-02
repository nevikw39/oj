#include "6034.hpp"

int main()
{
    vector<int> a = {1, 2, 3, 4, 5}, b = {5};
    Solution sln;
    cout << sln.triangularSum(a) << '\n'
         << sln.triangularSum(b) << '\n';
    return 0;
}
