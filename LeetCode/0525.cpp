#include "0525.hpp"

int main()
{
    vector<int> a = {0, 1}, b = {0, 1, 0};
    Solution sln;
    cout << sln.findMaxLength(a) << '\n'
         << sln.findMaxLength(b) << '\n';
    return 0;
}
