#include "1207.hpp"

int main()
{
    vector<int> a{1, 2, 2, 1, 1, 3}, b{1, 2}, c{-3, 0, 1, -3, 1, 1, 1, -3, 10, 0};
    Solution sln;
    cout << sln.uniqueOccurrences(a) << '\n'
         << sln.uniqueOccurrences(b) << '\n'
         << sln.uniqueOccurrences(c) << '\n';
    return 0;
}
