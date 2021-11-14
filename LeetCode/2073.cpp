#include "2073.hpp"

int main()
{
    vector<int> a = {2, 3, 2}, b = {5, 1, 1, 1};
    Solution sln;
    cout << sln.timeRequiredToBuy(a, 2) << '\n'
         << sln.timeRequiredToBuy(b, 0) << '\n';
    return 0;
}
