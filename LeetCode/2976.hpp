/**                  _ _              _____ ___
 *  _ __   _____   _(_) | ____      _|___ // _ \
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/
 **/
#ifndef nevikw39
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("abm,bmi,bmi2,mmx,sse,sse2,sse3,ssse3,sse4,popcnt,avx,avx2,fma,tune=native")
#pragma comment(linker, "/stack:200000000")
struct
{
    template <typename T>
    auto &operator<<(const T &x) { return *this; }
} __cerr;
#define cerr __cerr
#define __builtin_sprintf sprintf
#else
#pragma message("hello, nevikw39")
#endif
#pragma message("GL; HF!")
#include <bits/extc++.h>
#define ALL(X) begin(X), end(X)
#define ST first
#define ND second
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
template <typename T, typename Cmp = greater<T>, typename Tag = pairing_heap_tag>
using _heap = __gnu_pbds::priority_queue<T, Cmp, Tag>;
template <typename K, typename M = null_type, typename F = typename detail::default_hash_fn<K>::type>
using _hash = gp_hash_table<K, M, F>;
template <typename K, typename M = null_type, typename Cmp = less<K>, typename T = rb_tree_tag>
using _tree = tree<K, M, Cmp, T, tree_order_statistics_node_update>;

class Solution
{
    static constexpr auto INF = numeric_limits<int64_t>::max() >> 1;

public:
    long long minimumCost(const string &source, const string &target, const vector<char> &original, const vector<char> &changed, const vector<int> &cost)
    {
        array<array<int64_t, 26>, 26> d;
        ranges::fill(d | views::join, INF);
        for (int i : views::iota(0, 26))
            d[i][i] = 0;
        for (auto [u, v, w] : views::zip(original, changed, cost))
            d[u - 'a'][v - 'a'] = min(d[u - 'a'][v - 'a'], static_cast<int64_t>(w));
        for (int k : views::iota(0, 26))
            for (int i : views::iota(0, 26))
                for (int j : views::iota(0, 26))
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        int64_t sum = 0;
        for (auto [u, v] : views::zip(source, target))
            if (d[u - 'a'][v - 'a'] == INF)
                return -1;
            else
                sum += d[u - 'a'][v - 'a'];
        return sum;
    }
};
