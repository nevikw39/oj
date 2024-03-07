#include "0713.hpp"

int main()
{
    vector<int> arr{3, 2, 4}, a{10, 5, 2, 6}, b{1, 2, 3};
    Solution sln;
    cout << sln.numSubarrayProductLessThanK(arr, 7) << '\n'
         << sln.numSubarrayProductLessThanK(a, 100) << '\n'
         << sln.numSubarrayProductLessThanK(b, 0) << '\n';
    return 0;
}
