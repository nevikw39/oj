#include "2033.hpp"

int main()
{
    vector<vector<int>> a = {{2, 4}, {6, 8}}, b = {{2, 1}, {5, 3}}, c = {{1, 2}, {3, 4}};
    Solution sln;
    cout << sln.minOperations(a, 2) << '\n'
         << sln.minOperations(b, 1) << '\n'
         << sln.minOperations(c, 2) << '\n';
    return 0;
}
