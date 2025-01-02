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

constexpr array<bool, 26> _isvowel()
{
    array<bool, 26> y;
    y.fill(false);
    for (int i : views::iota(0, 26))
        switch ('a' + i)
        {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            y[i] = true;
        }
    return y;
}

class Solution
{
    static constexpr array<bool, 26> isvowel = _isvowel();

public:
    vector<int> vowelStrings(vector<string> &words, vector<vector<int>> &queries)
    {
        const int n = words.size(), q = queries.size();
        vector<int> ps(n), y(q);
        for (int i : views::iota(0, n))
            ps[i] = (i ? ps[i - 1] : 0) + (isvowel[words[i].front() - 'a'] && isvowel[words[i].back() - 'a']);
        for (int i : views::iota(0, q))
            y[i] = ps[queries[i].back()] - (queries[i].front() ? ps[queries[i].front() - 1] : 0);
        return y;
    }
};
