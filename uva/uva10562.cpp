#include <bits/extc++.h>
#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#endif
using namespace std;
using namespace __gnu_pbds;
int n;
vector<string> v;
void dfs(int r, int c)
{
    cout.put(v[r][c]).put('(');
    if (r + 1 < n && v[r + 1][c] == '|')
    {
        int i = c;
        while (i - 1 >= 0 && v[r + 2][i - 1] == '-')
            --i;
        while (v[r + 2][i] == '-' && v[r + 3][i])
        {
            if (!isspace(v[r + 3][i]))
                dfs(r + 3, i);
            i++;
        }
    }
    cout.put(')');
}
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    cin.ignore(1, '\n');
    while (t--)
    {
        n = 0;
        v.clear();
        for (;;)
        {
            string s;
            getline(cin, s);
            if (s[0] == '#')
                break;
            n++;
            v.push_back(s);
        }
        cout.put('(');
        if (n)
            for (int i = 0; i < v[0].length(); i++)
                if (v[0][i] != ' ')
                {
                    dfs(0, i);
                    break;
                }
        cout.put(')').put('\n');
    }
    return 0;
}