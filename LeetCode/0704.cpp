#include "0704.hpp"

int main()
{
    vector<int> a = {-1, 0, 3, 5, 9, 12}, b = {-1, 0, 3, 5, 9, 12};
    Solution sln;
    cout << sln.search(a, 9) << '\n'
         << sln.search(b, 2) << '\n';
    return 0;
}
