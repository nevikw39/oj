#include "0879.hpp"

int main()
{
    vector<int> a0{2, 2}, a1{2, 3}, b0{2, 3, 5}, b1{6, 7, 8};
    Solution sln;
    cout << sln.profitableSchemes(5, 3, a0, a1) << '\n'
         << sln.profitableSchemes(10, 5, b0, b1) << '\n';
    return 0;
}
