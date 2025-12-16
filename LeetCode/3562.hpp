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
    vector<vector<int>> t;

    tuple<vector<int>, vector<int>, int> dfs(int x, const vector<int> &present, const vector<int> &future, int budget)
    {
        const int cost = present[x], cost_d = cost >> 1;
        vector<int> dp0(budget + 1), dp1(budget + 1), child0(budget + 1), child1(budget + 1);;
        int size = cost;
        for (int i : t[x])
        {
            auto [i_dp0, i_dp1, i_size] = dfs(i, present, future, budget);
            size += i_size;
            for (int j = budget; ~j; j--)
                for (int k = 0; k <= min(j, i_size); k++)
                {
                    child0[j] = max(child0[j], child0[j - k] + i_dp0[k]);
                    child1[j] = max(child1[j], child1[j - k] + i_dp1[k]);
                }
        }
        for (int i = 0; i <= budget; i++)
        {
            dp0[i] = dp1[i] = child0[i];
            if (i >= cost_d)
                dp1[i] = max(dp0[i], child1[i - cost_d] + future[x] - cost_d);
            if (i >= cost)
                dp0[i] = max(dp1[i], child1[i - cost] + future[x] - cost);
        }
        return {dp0, dp1, size};
    }

public:
    int maxProfit(int n, const vector<int> &present, const vector<int> &future, const vector<vector<int>> &hierarchy, int budget)
    {
        t.assign(n, {});
        for (const auto &e : hierarchy)
            t[e.front() - 1].push_back(e.back() - 1);
        return get<0>(dfs(0, present, future, budget)).back();
    }
};
