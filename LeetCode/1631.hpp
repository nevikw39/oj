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
public:
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        const static pair<int, int> dirs[] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        int n = heights.size(), m = heights.front().size();
        vector<vector<int>> d(n, vector<int>(m, INT_MAX));
        _heap<tuple<int, int, int>> pq;
        vector<vector<decltype(pq)::point_iterator>> itrs(n, vector<decltype(pq)::point_iterator>(m));
        itrs[0][0] = pq.push({d[0][0] = 0, 0, 0});
        while (pq.size())
        {
            auto [_, i, j] = pq.top();
            pq.pop();
            if (i + 1 == n && j + 1 == m)
                return d[i][j];
            itrs[i][j] = nullptr;
            for (const auto &[di, dj] : dirs)
                if (0 <= i + di && i + di < n && 0 <= j + dj && j + dj < m && d[i + di][j + dj] > max(d[i][j], abs(heights[i][j] - heights[i + di][j + dj])))
                {
                    if (itrs[i + di][j + dj] != nullptr)
                        pq.modify(itrs[i + di][j + dj], {d[i + di][j + dj] = max(d[i][j], abs(heights[i][j] - heights[i + di][j + dj])), i + di, j + dj});
                    else
                        itrs[i + di][j + dj] = pq.push({d[i + di][j + dj] = max(d[i][j], abs(heights[i][j] - heights[i + di][j + dj])), i + di, j + dj});
                }
        }
        assert(false);
    }
};
