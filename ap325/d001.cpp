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
        return 2 * f() - 1;
    case 'g':
        return f() + 2 * f() - 3;
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