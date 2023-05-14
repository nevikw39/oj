#include "1799.hpp"

int main()
{
    vector a{1, 2}, b{3, 4, 6, 8}, c{1, 2, 3, 4, 5, 6}, d{773274, 313112, 131789, 222437, 918065, 49745, 321270, 74163, 900218, 80160, 325440, 961730};
    Solution sln;
    cout << sln.maxScore(a) << '\n'
         << sln.maxScore(b) << '\n'
         << sln.maxScore(c) << '\n'
         << sln.maxScore(d) << '\n';
    return 0;
}
