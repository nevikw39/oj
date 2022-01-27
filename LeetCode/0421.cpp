#include "0421.hpp"

int main()
{
    vector<int> a = {3, 10, 5, 25, 2, 8}, b = {14, 70, 53, 83, 49, 91, 36, 80, 92, 51, 66, 70};
    Solution sln;
    cout << sln.findMaximumXOR(a) << '\n'
         << sln.findMaximumXOR(b) << '\n';
    return 0;
}
