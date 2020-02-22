#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int a = 0, n = 0;
        for (const char &c : s)
            if (c == 'O')
                n += ++a;
            else
                a = 0;
        cout << n << '\n';
    }
    return 0;
}