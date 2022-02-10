#include "0560.hpp"

int main()
{
    vector<int> a = {1, 1, 1}, b = {1, 2, 3};
    Solution sln;
    cout << sln.subarraySum(a, 2) << '\n'
         << sln.subarraySum(b, 3) << '\n';
    return 0;
}
