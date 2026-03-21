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
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    std::copy_n(istream_iterator<string>(cin), h, s.begin());
    dsu disjoint_sets(h * w);
    for (auto [i, j] : views::cartesian_product(views::iota(0, h), views::iota(0, w)))
        if (s[i][j] == '.')
            for (auto &[di, dj] : {pair{0, 1}, pair{1, 0}, pair{0, -1}, pair{-1, 0}})
            {
                const int ip = i + di, jp = j + dj;
                if (0 <= ip && ip < h && 0 <= jp && jp < w && s[ip][jp] == '.')
                    disjoint_sets.merge(i * w + j, ip * w + jp);
            }
    vector<bool> v(h * w);
    for (int i : views::iota(0, h))
    {
        if (s[i].front() == '.')
            v[disjoint_sets.leader(i * w)] = true;
        if (s[i].back() == '.')
            v[disjoint_sets.leader(i * w + w - 1)] = true;
    }
    for (int j : views::iota(0, w))
    {
        if (s.front()[j] == '.')
            v[disjoint_sets.leader(j)] = true;
        if (s.back()[j] == '.')
            v[disjoint_sets.leader((h - 1) * w + j)] = true;
    }
    int cnt = 0;
    for (const auto &i : disjoint_sets.groups())
        if (s[i.front() / w][i.front() % w] == '.' && !v[disjoint_sets.leader(i.front())])
            ++cnt;
    println("{}", cnt);
    return 0;
}
