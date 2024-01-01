#include "0455.hpp"

int main()
{
    vector<int> a0{1, 2, 3}, a1{1, 1}, b0{1, 2}, b1{1, 2, 3};
    Solution sln;
    cout << sln.findContentChildren(a0, a1) << '\n'
         << sln.findContentChildren(b0, b1) << '\n';
    return 0;
}
