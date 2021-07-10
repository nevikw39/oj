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

int64_t dfs(vector<int64_t> &w, const vector<int64_t> &l, const vector<int64_t> &r, int64_t x)
{
    if (x >= l.size())
        return w[x];
    return w[x] = dfs(w, l, r, l[x]) + dfs(w, l, r, r[x]);
}

int main()
{
    nevikw39;
    int64_t n, m;
    cin >> n >> m;
    vector<int64_t> w(n << 1), l(n), r(n), v(m);
    for (int64_t i = n; i < (n << 1); i++)
        cin >> w[i];
    for (auto &i : v)
        cin >> i;
    for (int64_t i = 1; i < n; i++)
    {
        int p;
        cin >> p;
        cin >> l[p] >> r[p];
    }
    dfs(w, l, r, 1);
    for (const auto &i : v)
    {
        int x = 1;
        while (x < n)
        {
            if (w[l[x]] <= w[r[x]])
                x = l[x];
            else
                x = r[x];
            w[x] += i;
        }
        cout << x << ' ';
    }
    return 0;
}