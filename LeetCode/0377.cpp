#include "0377.hpp"

int main()
{
    vector<int> a{1, 2, 3}, b{9};
    Solution sln;
    cout << sln.combinationSum4(a, 4) << '\n'
         << sln.combinationSum4(b, 3) << '\n';
    return 0;
}
