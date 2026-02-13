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

// partially adapted from boost
inline void hash_combine(size_t &seed, int const &v)
{
    static hash<int> hasher;
    seed ^= hasher(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}

size_t hash_value(pair<int, int> const& v)
{
    size_t seed = 0;
    hash_combine(seed, v.first);
    hash_combine(seed, v.second);
    return seed;
}

template <class A, class B>
struct __hash { static size_t operator()(pair<A, B> const &val) { return hash_value(val); } };

class Solution
{
public:
    int longestBalanced(const string &s)
    {
        const int n = s.length();
        unordered_map<pair<int, int>, int, __hash<int, int>> a, b, c, ab, bc, ca, abc;
        a[{0, 0}] = b[{0, 0}] = c[{0, 0}] = ab[{0, 0}] = bc[{0, 0}] = ca[{0, 0}] = abc[{0, 0}] = -1;
        int arr[3] = {}, mx = 0;
        auto f = [&](auto &m, pair<int, int> key, int i)
        {
            auto itr = m.find(key);
            if (itr != m.end())
                mx = max(mx, i - itr->second);
            else
                m[key] = i;
        };
        for (int i : views::iota(0, n))
        {
            ++arr[s[i] - 'a'];
            f(a, {1[arr], 2[arr]}, i);
            f(b, {2[arr], 0[arr]}, i);
            f(c, {0[arr], 1[arr]}, i);
            f(ab, {1[arr] - 0[arr], 2[arr]}, i);
            f(bc, {2[arr] - 1[arr], 0[arr]}, i);
            f(ca, {0[arr] - 2[arr], 1[arr]}, i);
            f(abc, {1[arr] - 0[arr], 2[arr] - 0[arr]}, i);
        }
        return mx;
    }
};
