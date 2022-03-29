#include "0287.hpp"

int main()
{
    vector<int> a = {1, 3, 4, 2, 2}, b = {3, 1, 3, 4, 2};
    Solution sln;
    cout << sln.findDuplicate(a) << '\n'
         << sln.findDuplicate(b) << '\n';
    return 0;
}
