#include "2126.hpp"

int main()
{
    vector<int> a = {3, 9, 19, 5, 21}, b = {4, 9, 23, 4}, c = {1};
    Solution sln;
    cout << sln.asteroidsDestroyed(10, a) << '\n'
         << sln.asteroidsDestroyed(5, b) << '\n'
         << sln.asteroidsDestroyed(1, c) << '\n';
    return 0;
}
