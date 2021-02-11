#include <bits/extc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
template <typename T>
T inline bwmin(T x, T y)
{
    return y ^ ((x ^ y) & -(x < y));
}
template <typename T>
T inline bwmax(T x, T y)
{
    return x ^ ((x ^ y) & -(x < y));
}
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        string text;
        int q;
        cin >> text >> q;
        while (q--)
        {
            string pattern, s;
            cin >> pattern;
            s = pattern + '#' + text;
            int l = 0, r = 0, a = 0, len = s.length(), k = pattern.length();
            vector<int> z(len);
            for (int i = 1; i < len; i++)
            {
                z[i] = bwmax(bwmin(z[i - l], r - i), 0);
                while (i + z[i] < len && s[z[i]] == s[i + z[i]])
                    ++z[i];
                if (i + z[i] - 1 > r)
                {
                    l = i;
                    r = i + z[i] - 1;
                }
                if (z[i] == k)
                    ++a;
            }
            cout << a << '\n';
        }
    }
    return 0;
}