#include "1996.hpp"

int main()
{
    vector<vector<int>> a = {{5, 5}, {6, 3}, {3, 6}}, b = {{2, 2}, {3, 3}}, c = {{1, 5}, {10, 4}, {4, 3}}, d = {{1, 1}, {2, 1}, {2, 2}, {1, 2}}, e = {{7, 9}, {10, 7}, {6, 9}, {10, 4}, {7, 5}, {7, 10}}, f = {{8,9},{3,1},{6,6},{10,5},{7,7},{6,3}};
    Solution sln;
    cout << sln.numberOfWeakCharacters(a) << '\n'
         << sln.numberOfWeakCharacters(b) << '\n'
         << sln.numberOfWeakCharacters(c) << '\n'
         << sln.numberOfWeakCharacters(d) << '\n'
         << sln.numberOfWeakCharacters(e) << '\n'
         << sln.numberOfWeakCharacters(f) << '\n';
    return 0;
}
