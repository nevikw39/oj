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
    static constexpr pair<int, int> dirs[] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

public:
    int trapRainWater(vector<vector<int>> &heightMap)
    {
        const int n = heightMap.size(), m = heightMap.front().size();
        if (n == 1 || m == 1)
            return 0;
        _heap<tuple<int, int, int>> pq;
        for (const int i : views::iota(0, n))
        {
            pq.push({heightMap[i].front(), i, 0});
            pq.push({heightMap[i].back(), i, m - 1});
            heightMap[i].front() = heightMap[i].back() = -1;
        }
        for (const int j : views::iota(1, m - 1))
        {
            pq.push({heightMap.front()[j], 0, j});
            pq.push({heightMap.back()[j], n - 1, j});
            heightMap.front()[j] = heightMap.back()[j] = -1;
        }
        int y = 0;
        while (pq.size())
        {
            const auto [h, i, j] = pq.top();
            pq.pop();
            for (const auto [di, dj] : dirs)
            {
                const int ip = i + di, jp = j + dj;
                if (0 <= ip && ip < n && 0 <= jp && jp < m && heightMap[ip][jp] >= 0)
                {
                    if (heightMap[ip][jp] < h)
                    {
                        y += h - heightMap[ip][jp];
                        pq.push({h, ip, jp});
                    }
                    else
                        pq.push({heightMap[ip][jp], ip, jp});
                    heightMap[ip][jp] = -1;
                }
            }
        }
        return y;
    }
};
