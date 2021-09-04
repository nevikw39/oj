#include "5846.hpp"

int main()
{
    vector<int> a = {2, 3, -1, 8, 4}, b = {1, -1, 4}, c = {2, 5}, d = {1};
    Solution sln;
    cout << sln.findMiddleIndex(a) << '\n'
         << sln.findMiddleIndex(b) << '\n'
         << sln.findMiddleIndex(c) << '\n'
         << sln.findMiddleIndex(d) << '\n';
    return 0;
}
