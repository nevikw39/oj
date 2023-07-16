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
    vector<int> smallestSufficientTeam(vector<string> &req_skills, vector<vector<string>> &people)
    {
        _hash<string, int> hm;
        int n = req_skills.size(), m = people.size();
        for (int i = 0; i < n; i++)
            hm[req_skills[i]] = i;
        vector<int> v(m);
        for (int i = 0; i < m; i++)
            for (const auto &j : people[i])
                v[i] |= 1 << hm[j];
        vector<int64_t> dp(1 << n, (1LL << m) - 1);
        dp.front() = 0;
        for (int i = 1; i < 1 << n; i++)
            for (int j = 0; j < m; j++)
            {
                int k = i & ~v[j];
                if (__builtin_popcountl(dp[i]) > __builtin_popcountl(dp[k] | (1L << j)))
                    dp[i] = dp[k] | (1L << j);
            }
        vector<int> y;
        for (int i = 0; i < m; i++)
            if (dp.back() & (1L << i))
                y.push_back(i);
        return y;
    }
};
