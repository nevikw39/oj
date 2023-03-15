/**                  _ _              _____ ___
 *  _ __   _____   _(_) | ____      _|___ // _ \
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/
 **/
#include <bits/extc++.h>
#ifndef nevikw39
#define nevikw39 cin.tie(nullptr)->sync_with_stdio(false)
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("abm,bmi,bmi2,mmx,sse,sse2,sse3,ssse3,sse4,popcnt,avx,avx2,fma,tune=native")
#pragma comment(linker, "/stack:200000000")
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
using namespace __gnu_cxx;
using namespace __gnu_pbds;
template <typename T, typename Cmp = greater<T>, typename Tag = pairing_heap_tag>
using _heap = __gnu_pbds::priority_queue<T, Cmp, Tag>;
template <typename K, typename M = null_type>
using _hash = gp_hash_table<K, M>;
template <typename K, typename M = null_type, typename Cmp = less<K>, typename T = rb_tree_tag>
using _tree = tree<K, M, Cmp, T, tree_order_statistics_node_update>;

constexpr int N = 5e4;

vector<vector<int>> g, gp;
vector<bool> v;
vector<int> scc;
deque<int> dq;

void dfs_rev(int x)
{
    v[x] = true;
    for (int i : gp[x])
        if (!v[i])
            dfs_rev(i);
    dq.push_front(x);
}

void dfs(int x, int s)
{
    scc[x] = s;
    for (int i : g[x])
        if (!~scc[i])
            dfs(i, s);
}

int kosaraju(int n)
{
    for (int i = 0; i < n; i++)
        if (!v[i])
            dfs_rev(i);
    int cnt = 0;
    for (int i : dq)
        if (!~scc[i])
            dfs(i, cnt++);
    return cnt;
}

struct reachable_nodes
{
    vector<_hash<int>> g;
    vector<bitset<N>> v;

    void dfs(int x)
    {
        v[x][x] = true;
        for (int i : g[x])
        {
            if (v[i].none())
                dfs(i);
            v[x] |= v[i];
        }
    }

    reachable_nodes(int n, int cnt) : g(cnt), v(cnt)
    {
        for (int i = 0; i < n; i++)
            for (int j : ::g[i])
                if (scc[i] != scc[j])
                    g[scc[i]].insert(scc[j]);
        for (int i = 0; i < cnt; i++)
            if (v[i].none())
                dfs(i);
    }
};

int main()
{
    nevikw39;
    int n, m, q;
    cin >> n >> m >> q;
    g.assign(n, {});
    gp.assign(n, {});
    v.assign(n, false);
    scc.assign(n, -1);
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].push_back(b);
        gp[b].push_back(a);
    }
    reachable_nodes rn(n, kosaraju(n));
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        cout << (rn.v[scc[a]][scc[b]] ? "YES\n" : "NO\n");
    }
    return 0;
}
