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
template <typename T, typename Cmp = less<T>, typename Tag = pairing_heap_tag>
using _heap = __gnu_pbds::priority_queue<T, Cmp, Tag>;
template <typename K, typename M = null_type, typename F = typename detail::default_hash_fn<K>::type>
using _hash = gp_hash_table<K, M, F>;
template <typename K, typename M = null_type, typename Cmp = less<K>, typename T = rb_tree_tag>
using _tree = tree<K, M, Cmp, T, tree_order_statistics_node_update>;

class Solution
{
private:
    vector<vector<int64_t>> g;
    bitset<100> bs;
    int64_t y;
    void dfs(int x)
    {
        if (bs[x])
            return;
        bs[x] = true;
        ++y;
        for (const auto &i : g[x])
            dfs(i);
    }

public:
    int maximumDetonation(vector<vector<int>> &bombs)
    {
        int64_t n = bombs.size(), r = 1;
        g = vector<vector<int64_t>>(n);
        for (int64_t i = 0; i < n; i++)
            for (int64_t j = 0; j < i; j++)
            {
                int64_t dsq = 1LL * (bombs[i][0] - bombs[j][0]) * (bombs[i][0] - bombs[j][0]) + 1LL * (bombs[i][1] - bombs[j][1]) * (bombs[i][1] - bombs[j][1]);
                if (dsq <= 1LL * bombs[i][2] * bombs[i][2])
                    g[i].push_back(j);
                if (dsq <= 1LL * bombs[j][2] * bombs[j][2])
                    g[j].push_back(i);
            }
        for (int64_t i = 0; i < n; i++)
        {
            bs.reset();
            y = 0;
            dfs(i);
            r = max(r, y);
        }
        return r;
    }
};

