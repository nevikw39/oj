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
    bool f(const string &a, const string_view &b)
    {
        int l = a.length();
        if (l != b.length())
            return false;
        for (int i = 0; i < l; i++)
            if (a[i] != b[i] && a[i] != '?' && b[i] != '?')
                return false;
        return true;
    }

public:
    vector<int> movesToStamp(string stamp, string target)
    {
        int n = target.length(), m = stamp.length();
        vector<int> y;
        string_view sv(target);
        bool flag = true;
        while (flag)
        {
            flag = false;
            for (int i = 0; i <= n - m; i++)
            {
                auto ss = sv.substr(i, m);
                if (all_of(ALL(ss), [](char c)
                           { return c == '?'; }))
                    continue;
                if (f(stamp, ss))
                {
                    flag = true;
                    y.push_back(i);
                    fill(target.begin() + i, target.begin() + i + m, '?');
                }
            }
        }
        if (any_of(ALL(target), [](char c)
                   { return c != '?'; }) ||
            y.size() > n * 10)
            return {};
        reverse(ALL(y));
        return y;
    }
};
