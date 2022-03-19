#include "6022.hpp"

int main()
{
    vector<int> a = {5, 19, 8, 1}, b = {5, 8, 20};
    Solution sln;
    cout << sln.halveArray(a) << '\n'
         << sln.halveArray(b) << '\n';
    return 0;
}
