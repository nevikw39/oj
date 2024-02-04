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
    inline int f(char x) { return 26 * !(x & ' ') + (x | ' ') - 'a'; }

public:
    string minWindow(string s, string t)
    {
        int n = s.length(), m = t.length(), arr[52] = {}, l = 0, r = 0;
        for (char c : t)
            --arr[f(c)];
        while (r < n && m)
        {
            if (++arr[f(s[r])] <= 0)
                --m;
            ++r;
        }
        if (m)
            return "";
        while (arr[f(s[l])])
            --arr[f(s[l++])];
        int yl = l, yr = r;
        while (r < n)
        {
            ++arr[f(s[r++])];
            while (arr[f(s[l])])
                --arr[f(s[l++])];
            if (yr - yl > r - l)
            {
                yr = r;
                yl = l;
            }
        }
        return s.substr(yl, yr - yl);
    }
};
