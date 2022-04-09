#include "0923.hpp"

int main()
{
    vector<int> a = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5}, b = {1, 1, 2, 2, 2, 2};
    Solution sln;
    cout << sln.threeSumMulti(a, 8) << '\n'
         << sln.threeSumMulti(b, 5) << '\n';
    return 0;
}
