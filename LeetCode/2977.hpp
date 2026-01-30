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
    struct trie
    {
        static inline int sz;
        int id = -1;
        array<trie *, 26> ptrs{};
        int insert(const string &s, int i = 0)
        {
            if (i == s.length())
                return ~id ? id : (id = sz++);
            else
                return (ptrs[s[i] - 'a'] ?: ptrs[s[i] - 'a'] = new trie)->insert(s, i + 1);
        }
    };

public:
    long long minimumCost(const string &source, const string &target, const vector<string> &original, const vector<string> &changed, const vector<int> &cost)
    {
        trie::sz = 0;
        trie *root = new trie;
        const int n = source.length(), m = original.size();
        vector d(m << 1, vector<int64_t>(m << 1, INF));
        for (int i : views::iota(0, m << 1))
            d[i][i] = 0;
        for (auto [o, c, w] : views::zip(original, changed, cost))
        {
            const int u = root->insert(o), v = root->insert(c);
            d[u][v] = min(d[u][v], static_cast<int64_t>(w));
        }
        for (int k : views::iota(0, trie::sz))
            for (int i : views::iota(0, trie::sz))
                for (int j : views::iota(0, trie::sz))
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        vector<int64_t> dp(n, INF);
        for (int i : views::iota(0, n))
        {
            if (i && dp[i - 1] == INF)
                continue;
            const auto former = i ? dp[i - 1] : 0;
            if (source[i] == target[i])
                dp[i] = min(dp[i], former);
            trie *u = root, *v = root;
            for (int j : views::iota(i, n))
            {
                u = u->ptrs[source[j] - 'a'];
                v = v->ptrs[target[j] - 'a'];
                if (!u || !v)
                    break;
                const int uid = u->id, vid = v->id;
                if (~uid && ~vid && d[uid][vid] != INF)
                    dp[j] = min(dp[j], former + d[uid][vid]);
            }
        }
        return dp.back() != INF ? dp.back() : -1;
    }
};
