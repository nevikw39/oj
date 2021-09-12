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
private:
    string s, a, b;
    static int palindrome(const string &x, int l, int r)
    {
        if (l == r)
            return 1;
        if (x[l] == x[r] && r - l == 1)
            return 2;
        if (x[l] == x[r])
            return palindrome(x, l + 1, r - 1) + 2;
        return max(palindrome(x, l, r - 1), palindrome(x, l + 1, r));
    }
    int recur(int i)
    {
        if (i == s.length())
        {
            int pa = a.length() ? palindrome(a, 0, a.length() - 1) : 0, pb = b.length() ? palindrome(b, 0, b.length() - 1) : 0;
            return pa * pb;
        }
        a.push_back(s[i]);
        int y = recur(i + 1);
        a.pop_back();
        b.push_back(s[i]);
        y = max(y, recur(i + 1));
        b.pop_back();
        return y;
    }

public:
    int maxProduct(string _s)
    {
        s = move(_s);
        return recur(0);
    }
};
