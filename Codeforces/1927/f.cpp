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

struct disjoint_set
{
    int n, g;
    vector<int> p, sz;
    disjoint_set(int _n) : n(_n), g(n), p(n), sz(n, 1) { iota(ALL(p), 0); }
    int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
    bool unite(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
            return false;
        --g;
        if (sz[x] > sz[y])
            swap(x, y);
        sz[p[x] = y] += sz[x];
        return true;
    }
    bool same(int x, int y) { return find(x) == find(y); }
};

vector<vector<int>> mst;
vector<int> v;

bool dfs(int x, int y, int p = -1)
{
    if (x == y)
        return true;
    v.push_back(x + 1);
    for (int i : mst[x])
        if (i != p && dfs(i, y, x))
            return true;
    v.pop_back();
    return false;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    mst.assign(n, {});
    vector<tuple<int, int, int>> e(m); // edges: w, u, v
    for (auto &[w, u, v] : e)
    {
        cin >> u >> v >> w;
        --u;
        --v;
    }
    sort(ALL(e), greater<>());
    disjoint_set dsu(n);
    tuple<int, int, int> loop; // The edge of minimum weight not in the MST, which will form the loop with lightest weight when added into the MST
                               // Furthermore, the 2 endpoints of this loop edge would be the start and end of the loop;
    for (auto [w, u, v] : e)
        if (!dsu.unite(u, v))
            loop = {w, u, v};
        else
        {
            mst[u].push_back(v);
            mst[v].push_back(u);
        }
    v.clear();
    dfs(get<1>(loop), get<2>(loop));
    cout << get<0>(loop) << ' ' << v.size() + 1 << '\n';
    static ostream_iterator<int> ositr(cout, " ");
    copy(ALL(v), ositr);
    cout << get<2>(loop) + 1 << '\n';
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
