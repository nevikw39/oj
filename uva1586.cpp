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
        unordered_map<char, double> m;
        string s;
        cin >> s;
        auto l = s.length();
        for (int i = 0; i < l; i++)
        {
            int n = 0;
            char c;
            if (isupper(s[i]))
                c = s[i];
            while (i + 1 < l && isdigit(s[i + 1]))
            {
                n = n * 10 + s[i + 1] - '0';
                i++;
            }
            m[c] += n ?: 1;
        }
        cout << fixed << setprecision(3) << m['C'] * 12.01 + m['H'] * 1.008 + m['O'] * 16.00 + m['N'] * 14.01 << '\n';
    }
    return 0;
}