#include "1383.hpp"

int main()
{
    vector<int> a{2, 10, 3, 1, 5, 8}, b{5, 4, 3, 9, 7, 2};
    Solution sln;
    cout << sln.maxPerformance(6, a, b, 2) << '\n'
         << sln.maxPerformance(6, a, b, 3) << '\n'
         << sln.maxPerformance(6, a, b, 4) << '\n';
    return 0;
}
