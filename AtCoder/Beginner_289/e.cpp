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
using namespace atcoder;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
template <typename T, typename Cmp = greater<T>, typename Tag = pairing_heap_tag>
using _heap = __gnu_pbds::priority_queue<T, Cmp, Tag>;
template <typename K, typename M = null_type>
using _hash = gp_hash_table<K, M>;
template <typename K, typename M = null_type, typename Cmp = less<K>, typename T = rb_tree_tag>
using _tree = tree<K, M, Cmp, T, tree_order_statistics_node_update>;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<bool> c(n);
    for (int i = 0, cc; i < n; i++)
    {
        cin >> cc;
        c[i] = cc;
    }
    vector<vector<int>> g(n);
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<vector<bitset<2>>> v(n, vector<bitset<2>>(n));
    queue<tuple<int, int, int, bool>> q;
    q.emplace(0, n - 1, 0, true);
    q.emplace(0, n - 1, 0, false);
    while (q.size())
    {
        auto [t, a, d, flag] = q.front();
        q.pop();
        if (t == n - 1 && !a)
        {
            cout << d << '\n';
            return;
        }
        if (v[t][a][flag])
            continue;
        v[t][a][flag] = true;
        for (int i : g[t])
            if (c[i] == flag)
                for (int j : g[a])
                    if (c[j] != flag)
                    {
                        q.emplace(i, j, d + 1, true);
                        q.emplace(i, j, d + 1, false);
                    }
    }
    cout << "-1\n";
}

int main()
{
    nevikw39;
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
