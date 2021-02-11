#include <bits/extc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cc_hash_table<string, string> cc;
    cc["Mimi"] = "Moumou\n";
    cc["Moumou"] = "Mimi\n";
    int n, e;
    while (cin >> n >> e && n && e)
    {
        vector<int> d(n + 1);
        vector<bool> v(n + 1);
        vector<vector<int>> g(n + 1);
        while (e--)
        {
            int a, b;
            cin >> a >> b;
            g[b].push_back(a);
            ++d[a];
        }
        queue<int> q;
        q.push(n);
        v[n] = false;
        while (q.size())
        {
            int t = q.front();
            q.pop();
            for (const int &i : g[t])
            {
                --d[i];
                if (!v[t])
                    v[i] = true;
                if (!d[i])
                    q.push(i);
            }
        }
        string s;
        cin >> s;
        cout << (v[1] ? cc[s] : s + '\n');
    }
    return 0;
}