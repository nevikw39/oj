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

int cnt;
vector<int> p, heavy, head, sz, dep, dfn;
vector<vector<int>> t, decomposition;

void dfs(int x)
{
    sz[x] = 1;
    heavy[x] = -1;
    dep[x] = x != p[x] ? dep[p[x]] + 1 : 0;
    for (const int &i : t[x])
    {
        dfs(i);
        sz[x] += sz[i];
        if (!~heavy[x] || sz[i] > sz[heavy[x]])
            heavy[x] = i;
    }
}

void link(int x, int h)
{
    decomposition[h].push_back(x + 1);
    head[x] = h;
    dfn[x] = cnt++;
    if (~heavy[x])
        link(heavy[x], h);
    for (const int &i : t[x])
        if (i != heavy[x])
            link(i, i);
}

void solve()
{
    int n, root;
    cin >> n;
    p.resize(n);
    t.clear();
    t.resize(n);
    heavy.resize(n);
    head.resize(n);
    sz.resize(n);
    dep.resize(n);
    dfn.resize(n);
    decomposition.clear();
    decomposition.resize(n);
    cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
        if (--p[i] != i)
            t[p[i]].push_back(i);
        else
            root = i;
    }
    dfs(root);
    link(root, root);
    cout << count_if(ALL(decomposition), [](const auto &x)
                     { return x.size(); })
         << '\n';
    for (const auto &i : decomposition)
    {
        if (i.empty())
            continue;
        cout << i.size() << '\n';
        copy(ALL(i), ostream_iterator<int>(cout, " "));
        cout << '\n';
    }
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
