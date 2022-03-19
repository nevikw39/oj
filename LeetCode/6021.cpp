#include "6021.hpp"

int main()
{
    Solution sln;
    cout << sln.maximumSubsequenceCount("abdcdbc", "ac") << '\n'
         << sln.maximumSubsequenceCount("aabb", "ab") << '\n';
    return 0;
}
