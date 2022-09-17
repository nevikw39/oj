#include "6186.hpp"

int main()
{
    vector<int> a{1, 0, 2, 1, 3}, b{1, 2}, c{0};
    Solution sln;
    for (int i : sln.smallestSubarrays(a))
        cout << i << ' ';
    cout << '\n';
    for (int i : sln.smallestSubarrays(b))
        cout << i << ' ';
    cout << '\n';
    for (int i : sln.smallestSubarrays(c))
        cout << i << ' ';
    cout << '\n';
    return 0;
}
