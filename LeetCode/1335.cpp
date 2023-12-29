#include "1335.hpp"

int main()
{
    vector<int> a{6, 5, 4, 3, 2, 1}, b{9, 9, 9}, c{1, 1, 1}, d{7, 1, 7, 1, 7, 1};
    Solution sln;
    cout << sln.minDifficulty(a, 2) << '\n'
         << sln.minDifficulty(b, 4) << '\n'
         << sln.minDifficulty(c, 3) << '\n'
         << sln.minDifficulty(d, 3) << '\n';
    return 0;
}
