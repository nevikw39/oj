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
    set<array<int, 26>> s;
    array<int, 26> arr;

    static constexpr int factorial[] = {1, 1, 2, 6, 24, 120, 720, 5040};

    int permutation(int n)
    {
        int y = factorial[n];
        for (const int i : arr)
            y /= factorial[i];
        return y;
    }

    int backtrack(int x, string_view sv, int n)
    {
        if (x == sv.length())
        {
            if (s.count(arr))
                return 0;
            s.insert(arr);
            return permutation(n);
        }
        int y = backtrack(x + 1, sv, n);
        ++arr[sv[x] - 'A'];
        y += backtrack(x + 1, sv, n + 1);
        --arr[sv[x] - 'A'];
        return y;
    }

public:
    int numTilePossibilities(string tiles)
    {
        s.clear();
        arr.fill(0);
        return backtrack(0, tiles, 0) - 1;
    }
};
