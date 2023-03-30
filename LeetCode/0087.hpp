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
private:
    _hash<string, bool> dp;

    bool f(string s1, string s2)
    {
        if (s1 == s2)
            return true;
        int n = s1.length();
        if (n == 1 || n != s2.length())
            return false;
        auto s = s1 + '/' + s2;
        auto itr = dp.find(s);
        if (itr != dp.end())
            return itr->ND;
        for (int i = 1; i < n; i++)
            if (f(s1.substr(0, i), s2.substr(0, i)) && f(s1.substr(i), s2.substr(i))
             || f(s1.substr(0, i), s2.substr(n - i)) && f(s1.substr(i), s2.substr(0, n - i)))
                return dp[s] = true;
        return dp[s] = false;
    }

public:
    bool isScramble(string s1, string s2)
    {
        dp.clear();
        return f(s1, s2);
    }
};
