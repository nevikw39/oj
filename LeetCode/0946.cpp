#include "0946.hpp"

int main()
{
    vector<int> a0 = {1, 2, 3, 4, 5}, a1 = {4, 5, 3, 2, 1}, b0 = {1, 2, 3, 4, 5}, b1 = {4, 3, 5, 1, 2};
    Solution sln;
    cout << sln.validateStackSequences(a0, a1) << '\n'
         << sln.validateStackSequences(b0, b1) << '\n';
    return 0;
}
