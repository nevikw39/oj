#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
int f()
{
    string s;
    cin >> s;
    switch (s[0])
    {
    case 'f':
        return 2 * f() - 3;
    case 'g':
        return 2 * f() + f() - 7;
    case 'h':
        return 3 * f() - 2 * f() + f();
    default:
        return stoi(s);
    }
}
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << f() << '\n';
    return 0;
}