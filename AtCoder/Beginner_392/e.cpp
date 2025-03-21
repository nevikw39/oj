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

int main()
{
    nevikw39;
    int n, m;
    cin >> n >> m;
    atcoder::dsu disjoint_set(n);
    _hash<int, vector<int>> edges;
    for (const int i : views::iota(0, m))
    {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        if (disjoint_set.same(a, b))
            edges[a].push_back(i);
        else
            disjoint_set.merge(a, b);
    }
    _hash<int, vector<pair<int, int>>> group_edges;
    for (const int i : views::iota(0, n))
    {
        auto itr = group_edges.find(disjoint_set.leader(i));
        if (itr == group_edges.end())
            itr = group_edges.insert({disjoint_set.leader(i), {}}).ST;
        for (const int j : edges[i])
            itr->ND.emplace_back(i, j);
    }
    int g = group_edges.size(), to_merged = 0;
    cout << g - 1 << '\n';
    vector<pair<int, int>> groups;
    groups.reserve(group_edges.size());
    for (const auto &[group, edges] : group_edges)
        groups.emplace_back(edges.size(), group);
    ranges::sort(groups, greater<>());
    for (const auto &[_, group] : groups)
        for (const auto &[i, j] : group_edges[group])
            if (to_merged + 1 < g)
                cout << j + 1 << ' ' << i + 1 << ' ' << groups[++to_merged].ND + 1 << '\n';
    return 0;
}
