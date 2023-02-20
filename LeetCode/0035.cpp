#include "0035.hpp"

int main()
{
    vector<int> v{1, 3, 5, 6};
    Solution sln;
    cout << sln.searchInsert(v, 5) << '\n'
         << sln.searchInsert(v, 2) << '\n'
         << sln.searchInsert(v, 7) << '\n';
    return 0;
}
