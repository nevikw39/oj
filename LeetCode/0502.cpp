#include "0502.hpp"

int main()
{
    vector<int> a0{1, 2, 3}, a1{0, 1, 1}, b0{1, 2, 3}, b1{0, 1, 2};
    Solution sln;
    cout << sln.findMaximizedCapital(2, 0, a0, a1) << '\n'
         << sln.findMaximizedCapital(3, 0, b0, b1) << '\n';
    return 0;
}
