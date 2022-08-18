#include "1338.hpp"

int main()
{
    vector<int> a{3, 3, 3, 3, 5, 5, 5, 2, 2, 7}, b{7, 7, 7, 7, 7, 7}, c{1, 9};
    Solution sln;
    cout << sln.minSetSize(a) << '\n'
         << sln.minSetSize(b) << '\n'
         << sln.minSetSize(c) << '\n';
    return 0;
}
