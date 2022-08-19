#include "0659.hpp"

int main()
{
    vector<int> a{1, 2, 3, 3, 4, 5}, b{1, 2, 3, 3, 4, 4, 5, 5}, c{1, 2, 3, 4, 4, 5};
    Solution sln;
    cout << sln.isPossible(a) << '\n'
         << sln.isPossible(b) << '\n'
         << sln.isPossible(c) << '\n';
    return 0;
}
