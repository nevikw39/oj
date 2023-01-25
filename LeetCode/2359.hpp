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
    int closestMeetingNode(vector<int> &edges, int node1, int node2)
    {
        int n = edges.size();
        vector<int> d1(n, INT_MAX), d2(n, INT_MAX);
        d1[node1] = d2[node2] = 0;
        queue<int> q;
        q.push(node1);
        while (q.size())
        {
            int f = q.front();
            q.pop();
            if (~edges[f] && d1[edges[f]] > d1[f] + 1)
            {
                d1[edges[f]] = d1[f] + 1;
                q.push(edges[f]);
            }
        }
        q.push(node2);
        while (q.size())
        {
            int f = q.front();
            q.pop();
            if (~edges[f] && d2[edges[f]] > d2[f] + 1)
            {
                d2[edges[f]] = d2[f] + 1;
                q.push(edges[f]);
            }
        }
        int y = 0;
        for (int i = 1; i < n; i++)
            if (max(d1[y], d2[y]) > max(d1[i], d2[i]))
                y = i;
        return max(d1[y], d2[y]) != INT_MAX ? y : -1;
    }
};
