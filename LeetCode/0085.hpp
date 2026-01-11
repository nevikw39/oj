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
    int largestRectangleArea_dc(const vector<int>::iterator &l, const vector<int>::iterator &r)
    {
        if (r <= l)
            return 0;
        if (r - l == 1)
            return *l;
        auto m = l + ((r - l) >> 1), itr = m, jtr = m;
        int y = max(largestRectangleArea_dc(l, m), largestRectangleArea_dc(m, r)), h = *m;
        while (itr >= l || jtr < r)
        {
            h = max(itr >= l ? *itr : INT64_MIN, jtr < r ? *jtr : INT64_MIN);
            while (itr >= l && *itr >= h)
                --itr;
            while (jtr < r && *jtr >= h)
                ++jtr;
            y = max(y, int(jtr - itr - 1) * h);
        }
        return y;
    }

public:
    int maximalRectangle(const vector<vector<char>> &matrix)
    {
        const int rows = matrix.size(), cols = matrix.front().size();
        vector<int> h(cols);
        int mx = 0;
        for (int i : views::iota(0, rows))
        {
            for (int j : views::iota(0, cols))
                if (matrix[i][j] == '1')
                    ++h[j];
                else
                    h[j] = 0;
            mx = max(mx, largestRectangleArea_dc(ALL(h)));
        }
        return mx;
    }
};
