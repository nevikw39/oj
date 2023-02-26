#include "0045.hpp"

int main()
{
    Solution sln;
    vector<int> a{2, 3, 1, 1, 4}, b{2, 3, 0, 1, 4};
    cout << sln.jump(a) << '\n'
         << sln.jump(b) << '\n';
    return 0;
}
