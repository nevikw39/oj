#include <bits/extc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, m, l, q;
    cin >> n >> m >> l >> q;
    vector<vector<int>> v(n + 1);
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
    }
    cc_hash_table<int, null_type> c;
    deque<int> d;
    while (l--)
    {
        int x;
        cin >> x;
        c.insert(x);
        d.push_back(x);
    }
    while (d.size())
    {
        int t = d.back();
        d.pop_back();
        for (const int &i : v[t])
            if (c.find(i) == c.end())
            {
                c.insert(i);
                d.push_back(i);
            }
    }
    while (q--)
    {
        int y;
        cin >> y;
        cout << (c.find(y) == c.end() ? "YA~~\n" : "TUIHUOOOOOO\n");
    }
    return 0;
}