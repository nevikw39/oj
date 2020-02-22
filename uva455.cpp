#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
bool f(const string &s, int k)
{
    int l = s.length();
    for (int i = 1; i < l / k; i++)
        for (int j = i * k; j < (i + 1) * k; j++)
            if (s[j] != s[j % k])
                return false;
    return true;
}
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
        int l = s.length();
        for (int i = 1; i <= l; i++)
            if (!(l % i) && f(s, i))
            {
                cout << i << '\n';
                break;
            }
        if (t)
            cout << '\n';
    }
    return 0;
}