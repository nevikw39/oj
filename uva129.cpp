#include <bits/extc++.h>
#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#endif
using namespace std;
using namespace __gnu_pbds;
int n, l, cnt;
vector<int> v;
bool dfs(int x)
{
    if (cnt++ == n)
    {
        for (int i = 0; i < x; i++)
        {
            cout.put('A' + v[i]);
            if (!((i + 1) & 63) && i + 1 < x)
                cout.put('\n');
            else if (!((i + 1) & 3) && i + 1 < x)
                cout.put(' ');
        }
        cout << '\n' << x << '\n';
        return true;
    }
    v.emplace_back();
    for (int i = 0; i < l; i++)
    {
        v[x] = i;
        bool flag = true;
        for (int j = 1; j << 1 <= x + 1 && flag; j++)
        {
            bool flag1 = false;
            for (int k = 0; k < j && !flag1; k++)
                if (v[x - k] != v[x - k - j])
                    flag1 = true;
            if (!flag1)
                flag = false;
        }
        if (flag && dfs(x + 1))
            return true;
    }
    return false;
}
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    while (cin >> n >> l && n)
    {
        cnt = 0;
        v.clear();
        dfs(0);
    }
    return 0;
}