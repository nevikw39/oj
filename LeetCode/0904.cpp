#include "0904.hpp"

int main()
{
    Solution sln;
    vector<int> a{1, 2, 1}, b{0, 1, 2, 2}, c{1, 2, 3, 2, 2};
    cout << sln.totalFruit(a) << '\n'
         << sln.totalFruit(b) << '\n'
         << sln.totalFruit(c) << '\n';
    return 0;
}
