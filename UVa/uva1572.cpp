#include <bits/extc++.h>
#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#endif
using namespace std;
using namespace __gnu_pbds;
int inline foo(char a, char b)
{
    return a - 'A' + (b == '+' ? 0 : 26);
}
int inline bar(char a, char b)
{
    return a - 'A' + (b == '+' ? 26 : 0);
}
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    while (cin >> n)
    {
        bool flag = false, g[52][52];
        memset(g, 0, sizeof(g));
        while (n--)
        {
            string s;
            cin >> s;
            for (int i = 0; i < 4; i++)
                for (int j = 0; j < 4; j++)
                {
                    if (i == j || s[i << 1] == '0' || s[j << 1] == '0')
                        continue;
                    g[foo(s[i << 1], s[i << 1 | 1])][bar(s[j << 1], s[j << 1 | 1])] = true;
                }
        }
        for (int k = 0; k < 52; k++)
            for (int i = 0; i < 52; i++)
                for (int j = 0; j < 52; j++)
                    g[i][j] |= g[i][k] & g[k][j];
        for (int i = 0; i < 52; i++)
            flag |= g[i][i];
        cout << (flag ? "un" : "") << "bounded\n";
    }
    return 0;
}