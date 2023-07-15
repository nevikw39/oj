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

int n, t, m;
vector<_hash<int>> v;
vector<set<int>> vs;
map<set<set<int>>, bool> mp;

inline set<set<int>> f() { return set(ALL(vs)); }

void dfs(int x = 0)
{
    if (mp.count(f()))
        return;
    if (x == n)
    {
        mp[f()] = true;
        // assert(accumulate(ALL(vs), 0, [](int x, const auto &y){ return x + y.size(); }) == n);
        return;
    }
    mp[f()] = false;
    for (int i = 0; i < t; i++)
        if (all_of(ALL(v[x]), [&](int x){ return !vs[i].count(x); }))
        {
            vs[i].insert(x);
            dfs(x + 1);
            vs[i].erase(x);
        }
}

int main()
{
    nevikw39;
    cin >> n >> t >> m;
    v.resize(n);
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        v[a].insert(b);
        v[b].insert(a);
    }
    vs.resize(t);
    dfs();
    cout << count_if(ALL(mp), [](const auto &x){ return x.ND && all_of(ALL(x.ST), [](const auto &x){ return x.size(); }); }) << '\n';
    return 0;
}
