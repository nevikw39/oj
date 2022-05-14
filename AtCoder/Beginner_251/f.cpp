/**                  _ _              _____ ___
 *  _ __   _____   _(_) | ____      _|___ // _ \
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/
 **/
#include <atcoder/all>
#include <bits/extc++.h>
#ifndef nevikw39
#define nevikw39 cin.tie(nullptr)->sync_with_stdio(false)
struct
{
    template <typename T>
    auto &operator<<(const T &x) { return *this; }
} __cerr;
#define cerr __cerr
#else
#pragma message("hello, nevikw39")
#endif
#pragma message("GL; HF!")
#define ALL(X) begin(X), end(X)
#define ST first
#define ND second
using namespace std;
using namespace atcoder;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
template <typename T, typename Cmp = greater<T>, typename Tag = pairing_heap_tag>
using _heap = __gnu_pbds::priority_queue<T, Cmp, Tag>;
template <typename K, typename M = null_type>
using _hash = gp_hash_table<K, M>;
template <typename K, typename M = null_type, typename Cmp = less<K>, typename T = rb_tree_tag>
using _tree = tree<K, M, Cmp, T, tree_order_statistics_node_update>;

vector<vector<int>> g, t1, t2;
vector<bool> v;

void dfs(int x = 0, int p = -1)
{
    if (v[x])
        return;
    v[x] = true;
    if (~p)
        t1[p].push_back(x);
    for (int &i : g[x])
        if (i != p)
            dfs(i, x);
}

int main()
{
    nevikw39;
    int n, m;
    cin >> n >> m;
    g.resize(n);
    v.resize(n);
    t1.resize(n);
    t2.resize(n);
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs();
    for (int i = 0; i < n; i++)
        for (const int &j : t1[i])
            cout << i + 1 << ' ' << j + 1 << '\n';
    vector<bool> v(n);
    v[0] = true;
    queue<int> q;
    q.push(0);
    while (q.size())
    {
        int f = q.front();
        q.pop();
        for (const int &i : g[f])
            if (!v[i])
            {
                v[i] = true;
                q.push(i);
                t2[f].push_back(i);
            };
    }
    for (int i = 0; i < n; i++)
        for (const int &j : t2[i])
            cout << i + 1 << ' ' << j + 1 << '\n';
    return 0;
}
