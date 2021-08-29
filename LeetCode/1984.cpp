#include "1984.hpp"

int main()
{
    vector<int> a = {90}, b = {9, 4, 1, 7};
    Solution sln;
    cout << sln.minimumDifference(a, 1) << '\n'
         << sln.minimumDifference(b, 2) << '\n';
    return 0;
}
