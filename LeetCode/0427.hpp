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
// using namespace __gnu_cxx;
using namespace __gnu_pbds;
template <typename T, typename Cmp = greater<T>, typename Tag = pairing_heap_tag>
using _heap = __gnu_pbds::priority_queue<T, Cmp, Tag>;
template <typename K, typename M = null_type, typename F = typename detail::default_hash_fn<K>::type>
using _hash = gp_hash_table<K, M, F>;
template <typename K, typename M = null_type, typename Cmp = less<K>, typename T = rb_tree_tag>
using _tree = tree<K, M, Cmp, T, tree_order_statistics_node_update>;

class Solution
{
private:
    static int bwavg(int l, int r) { return (l & r) + ((l ^ r) >> 1); }
    Node *f(int x0, int y0, int x1, int y1, const vector<vector<int>> &grid)
    {
        for (int i = x0; i < x1; i++)
            for (int j = y0; j < y1; j++)
                if (grid[i][j] != grid[x0][y0])
                {
                    int x = bwavg(x0, x1), y = bwavg(y0, y1);
                    return new Node(false, false,
                                    f(x0, y0, x, y, grid),
                                    f(x0, y, x, y1, grid),
                                    f(x, y0, x1, y, grid),
                                    f(x, y, x1, y1, grid));
                }
        return new Node(grid[x0][y0], true);
    }

public:
    Node *construct(vector<vector<int>> &grid) { return f(0, 0, grid.size(), grid.front().size(), grid); }
};
