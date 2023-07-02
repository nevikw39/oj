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
    int m;
    vector<pair<int, int>> v;
    vector<int> deg;
    int f(int x = 0, int cnt = 0)
    {
        if (x == m)
            return none_of(ALL(deg), [](int x){ return x; }) ? cnt : 0;
        int y = f(x + 1, cnt);
        --deg[v[x].ST];
        ++deg[v[x].ND];
        y = max(y, f(x + 1, cnt + 1));
        --deg[v[x].ND];
        ++deg[v[x].ST];
        return y;
    }

public:
    int maximumRequests(int n, vector<vector<int>> &requests)
    {
        m = requests.size();
        v.reserve(m);
        for (const auto &i : requests)
            v.emplace_back(i[0], i[1]);
        deg.assign(n, 0);
        return f();
    }
};
