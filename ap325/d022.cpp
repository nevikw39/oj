/**                  _ _              _____ ___  
 *  _ __   _____   _(_) | ____      _|___ // _ \ 
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/ 
 **/
#include <bits/extc++.h>
#include <bits/stdc++.h>
#ifndef nevikw39
#define nevikw39      \
    cin.tie(nullptr); \
    ios::sync_with_stdio(false);
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("abm,bmi,bmi2,mmx,sse,sse2,sse3,ssse3,sse4,popcnt,avx,avx2,fma,tune=native")
#pragma comment(linker, "/stack:200000000")
struct _cerr
{
    template <typename T>
    _cerr &operator<<(const T &x) { return *this; }
} __cerr;
#define cerr __cerr
#else
#pragma message("hello, nevikw39")
#endif
#pragma message("GL; HF!")
#define ALL(X) begin(X), end(X)
#define ST first
#define ND second
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
template <typename K, typename M = null_type, typename Cmp = less<K>, typename T = rb_tree_tag>
using _tree = __gnu_pbds::tree<K, M, Cmp, T, tree_order_statistics_node_update>;
template <typename T>
using _heap = __gnu_pbds::priority_queue<T>;
template <typename K, typename M = null_type>
using _hash = gp_hash_table<K, M>;

constexpr long long p = 1e9 + 9;

using pll = pair<long long, long long>;

pll operator*(const pll &l, const pll &r)
{
    return {(l.ST * r.ST % p + (l.ND * r.ND << 1) % p) % p, (l.ST * r.ND % p + l.ND * r.ST % p) % p};
}

pll binpow(pll a, long long n)
{
    pll y = a;
    for (; n; n >>= 1, a = a * a)
        if (n & 1)
            y = y * a;
    return y;
}

int main()
{
    nevikw39;
    long long x, y, n;
    cin >> x >> y >> n;
    auto r = binpow({x, y}, --n);
    cout << r.ST << ' ' << r.ND << '\n';
    return 0;
}