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
#define RALL(X) rbegin(X), rend(X)
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
    int snakesAndLadders(vector<vector<int>> &board)
    {
        int n = board.size() * board.size();
        vector<int> v, d(n, INT_MAX);
        reverse(ALL(board));
        bool flag = true;
        for (const auto &i : board)
        {
            if (flag)
                copy(ALL(i), back_inserter(v));
            else
                copy(RALL(i), back_inserter(v));
            flag ^= true;
        }
        d.front() = 0;
        queue<int> q;
        q.push(0);
        while (q.size())
        {
            int f = q.front();
            if (f == n - 1)
                return d.back();
            q.pop();
            for (int i = 1; i <= 6 && f + i < n; i++)
            {
                int x = ~v[i + f] ? v[i + f] - 1 : i + f;
                if (d[x] > d[f] + 1)
                {
                    d[x] = d[f] + 1;
                    q.push(x);
                }
            }
        }
        return -1;
    }
};
