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

struct disjoint_set
{
    int n;
    vector<int> p, sz;
    disjoint_set(int _n) : n(_n), sz(_n, 1), p(_n) { iota(ALL(p), 0); }
    int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
    bool unite(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
            return false;
        if (sz[x] < sz[y])
            swap(x, y);
        p[y] = x;
        sz[x] += sz[y];
        return true;
    }
};

class Solution
{
public:
    vector<long long> maximumSegmentSum(vector<int> &nums, vector<int> &removeQueries)
    {
        int n = nums.size();
        vector<long long> y(n), v(n);
        disjoint_set dsu(n);
        reverse(ALL(removeQueries));
        for (int i = 0; i + 1 < n; i++)
        {
            int j = removeQueries[i];
            v[j] = nums[j];
            if (j && v[j - 1] && dsu.find(j - 1) != dsu.find(j))
            {
                auto tmp = v[dsu.find(j - 1)] + v[dsu.find(j)];
                dsu.unite(j - 1, j);
                v[dsu.find(j)] = tmp;
            }
            if (j + 1 < n && v[j + 1] && dsu.find(j + 1) != dsu.find(j))
            {
                auto tmp = v[dsu.find(j + 1)] + v[dsu.find(j)];
                dsu.unite(j + 1, j);
                v[dsu.find(j)] = tmp;
            }
            y[i + 1] = max(y[i], v[dsu.find(j)]);
        }
        reverse(ALL(y));
        return y;
    }
};
