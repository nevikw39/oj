#include "6024.hpp"

int main()
{
    vector<int> a = {1, 100, 200, 1, 100}, b = {2,2,2,2,3};
    Solution sln;
    cout << sln.mostFrequent(a, 1) << '\n'
         << sln.mostFrequent(b, 2) << '\n';
    return 0;
}
