#include "2870.hpp"

int main()
{
    vector<int> a{2, 3, 3, 2, 2, 4, 2, 3, 4}, b{2, 1, 2, 2, 3, 3};
    Solution sln;
    cout << sln.minOperations(a) << '\n'
         << sln.minOperations(b) << '\n';
    return 0;
}
