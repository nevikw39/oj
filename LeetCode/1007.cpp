#include "1007.hpp"

int main()
{
    vector<int> a0 = {2, 1, 2, 4, 2, 2}, a1 = {5, 2, 6, 2, 3, 2}, b0 = {3, 5, 1, 2, 3}, b1 = {3, 6, 3, 3, 4};
    Solution sln;
    cout << sln.minDominoRotations(a0, a1) << '\n'
         << sln.minDominoRotations(b0, b1) << '\n';
    return 0;
}
