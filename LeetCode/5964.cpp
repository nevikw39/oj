#include "5964.hpp"

int main()
{
    vector<int> a = {0, 1}, b = {1, 1}, c = {0, 0};
    Solution sln;
    for (auto &&i : sln.executeInstructions(3, a, "RRDDLU"))
        cout << i << '\n';
    cout << '\n';
    for (auto &&i : sln.executeInstructions(2, b, "LURD"))
        cout << i << '\n';
    cout << '\n';
    for (auto &&i : sln.executeInstructions(1, c, "LRUD"))
        cout << i << '\n';
    cout << '\n';
    return 0;
}
