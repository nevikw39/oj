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
public:
    int countPaths(int n, vector<vector<int>> &roads)
    {
        vector<vector<pair<long long, long long>>> g(n);
        vector<bool> v(n);
        for (const auto &i : roads)
        {
            g[i[0]].emplace_back(i[1], i[2]);
            g[i[1]].emplace_back(i[0], i[2]);
        }
        vector<long long> d(n, LLONG_MAX), r(n);
        d[0] = 0;
        r[0] = 1;
        std::priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
        pq.emplace(0, 0);
        while (pq.size())
        {
            auto f = pq.top();
            pq.pop();
            if (v[f.ND])
                continue;
            v[f.ND] = true;
            for (const auto &i : g[f.ND])
                if (d[i.ST] > d[f.ND] + i.ND)
                {
                    d[i.ST] = d[f.ND] + i.ND;
                    r[i.ST] = r[f.ND] %= 1000000007;
                    pq.emplace(f.ST + i.ND, i.ST);
                }
                else if (d[i.ST] == d[f.ND] + i.ND)
                    r[i.ST] += r[f.ND], r[i.ST] %= 1000000007;
        }
        return r.back();
    }
};
