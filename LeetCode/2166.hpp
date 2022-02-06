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

class Bitset
{
    vector<bool> v;
    int n, cnt;

public:
    Bitset(int size)
    {
        n = size;
        v.resize(n);
        cnt = 0;
    }

    void fix(int idx)
    {
        if (v[idx])
            return;
        v[idx] = true;
        ++cnt;
    }

    void unfix(int idx)
    {
        if (!v[idx])
            return;
        v[idx] = false;
        --cnt;
    }

    void flip()
    {
        v.flip();
        cnt = n - cnt;
    }

    bool all() { return cnt == n; }

    bool one() { return cnt; }

    int count() { return cnt; }

    string toString()
    {
        string y;
        for (auto &&i : v)
            if (i)
                y.push_back('1');
            else
                y.push_back('0');
        return y;
    }
};
