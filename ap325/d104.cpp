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
template <typename T, typename Cmp = less<T>, typename Tag = pairing_heap_tag>
using _heap = __gnu_pbds::priority_queue<T, Cmp, Tag>;
template <typename K, typename M = null_type>
using _hash = gp_hash_table<K, M>;
template <typename K, typename M = null_type, typename Cmp = less<K>, typename T = rb_tree_tag>
using _tree = tree<K, M, Cmp, T, tree_order_statistics_node_update>;

void dfs(const vector<vector<pair<int64_t, int64_t>>> &c, vector<int64_t> &s, int64_t &me, int64_t &r, int64_t x)
{
    for (const auto &i : c[x])
    {
        dfs(c, s, me, r, i.ST);
        r += min(s[i.ST], int64_t(s.size()) - s[i.ST]) * i.ND;
        s[x] += s[i.ST];
    }
    ++s[x];
    if (me < 0 && s[x] >= (s.size() >> 1))
        me = x;
}

int main()
{
    nevikw39;
    int64_t n, me = -1, r = 0;
    cin >> n;
    vector<vector<pair<int64_t, int64_t>>> c(n);
    vector<int64_t> s(n);
    for (int64_t i = 1; i < n; i++)
    {
        int64_t x, w;
        cin >> x >> w;
        c[x].emplace_back(i, w);
    }
    dfs(c, s, me, r, 0);
    cout << me << '\n'
         << r << '\n';
    return 0;
}