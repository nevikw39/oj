#include "2216.hpp"

int main()
{
    vector<int> a = {1, 1, 2, 3, 5}, b = {1, 1, 2, 2, 3, 3}, c = {5, 1, 5, 4, 8, 1, 4, 4, 1, 9, 2, 2, 2, 5, 1};
    Solution sln;
    cout << sln.minDeletion(a) << '\n'
         << sln.minDeletion(b) << '\n'
         << sln.minDeletion(c) << '\n';
    return 0;
}
