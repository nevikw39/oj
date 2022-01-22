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
    struct node
    {
        int d, p, r, c;
        bool operator<(const node &x)
        {
            if (d != x.d)
                return d < x.d;
            if (p != x.p)
                return p < x.p;
            if (r != x.r)
                return r < x.r;
            return c < x.c;
        }
    };

public:
    vector<vector<int>> highestRankedKItems(vector<vector<int>> &grid, vector<int> &pricing, vector<int> &start, int k)
    {
        int n = grid.size(), m = grid[0].size();
        vector<node> v;
        vector<vector<int>> d(n, vector<int>(m, INT_MAX));
        queue<pair<int, int>> q;
        q.emplace(start[0], start[1]);
        d[start[0]][start[1]] = 0;
        while (q.size())
        {
            auto f = q.front();
            q.pop();
            if (pricing[0] <= grid[f.ST][f.ND] && grid[f.ST][f.ND] <= pricing[1])
                v.push_back({d[f.ST][f.ND], grid[f.ST][f.ND], f.ST, f.ND});
            if (f.ST + 1 < n && d[f.ST + 1][f.ND] == INT_MAX && grid[f.ST + 1][f.ND])
            {
                d[f.ST + 1][f.ND] = d[f.ST][f.ND] + 1;
                q.emplace(f.ST + 1, f.ND);
            }
            if (f.ND + 1 < m && d[f.ST][f.ND + 1] == INT_MAX && grid[f.ST][f.ND + 1])
            {
                d[f.ST][f.ND + 1] = d[f.ST][f.ND] + 1;
                q.emplace(f.ST, f.ND + 1);
            }
            if (f.ST - 1 >= 0 && d[f.ST - 1][f.ND] == INT_MAX && grid[f.ST - 1][f.ND])
            {
                d[f.ST - 1][f.ND] = d[f.ST][f.ND] + 1;
                q.emplace(f.ST - 1, f.ND);
            }
            if (f.ND - 1 >= 0 && d[f.ST][f.ND - 1] == INT_MAX && grid[f.ST][f.ND - 1])
            {
                d[f.ST][f.ND - 1] = d[f.ST][f.ND] + 1;
                q.emplace(f.ST, f.ND - 1);
            }
        }
        sort(ALL(v));
        n = min(k, int(v.size()));
        vector<vector<int>> y(n, vector<int>(2));
        for (int i = 0; i < n; i++)
            y[i][0] = v[i].r, y[i][1] = v[i].c, cerr << v[i].d << '\n';
        return y;
    }
};
