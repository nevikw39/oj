#include "2971.hpp"

int main()
{
    vector<int> a{5, 5, 5}, b{1, 12, 1, 2, 5, 50, 3}, c{5, 5, 50};
    Solution sln;
    cout << sln.largestPerimeter(a) << '\n'
         << sln.largestPerimeter(b) << '\n'
         << sln.largestPerimeter(c) << '\n';
    return 0;
}
