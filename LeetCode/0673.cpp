#include "0673.hpp"

int main()
{
    vector<int> a{1, 3, 5, 4, 7}, b(5, 2);
    Solution sln;
    cout << sln.findNumberOfLIS(a) << '\n'
         << sln.findNumberOfLIS(b) << '\n';
    return 0;
}
