#include <cstdint>
#include <iostream>
#include <set>
#pragma GCC optimize("O3")
using namespace std;
int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    set<int> s;
    for (long i = 1; i < __INT_MAX__; i *= 2)
        s.insert(i);
    int n;
    while (cin >> n)
        cout << (s.count(n) ? "Yes\n" : "No\n");
    return 0;
}