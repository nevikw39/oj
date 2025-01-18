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
    static constexpr int di[] = {0, 0, 1, -1}, dj[] = {1, -1, 0, 0};

public:
    int minCost(vector<vector<int>> &grid)
    {
        const int n = grid.size(), m = grid.front().size();
        vector d(n, vector<int>(m, numeric_limits<int>::max()));
        d.front().front() = 0;
        deque<pair<int, int>> dq{{0, 0}};
        while (dq.size())
        {
            const auto [i, j] = dq.front();
            dq.pop_front();
            for (const int k : views::iota(0, 4))
            {
                const int ip = i + di[k], jp = j + dj[k], weight = grid[i][j] != k + 1;
                if (0 <= ip && ip < n && 0 <= jp && jp < m && d[ip][jp] > d[i][j] + weight)
                {
                    d[ip][jp] = d[i][j] + weight;
                    if (weight)
                        dq.emplace_back(ip, jp);
                    else
                        dq.emplace_front(ip, jp);
                }
            }
        }
        return d.back().back();
    }
};
