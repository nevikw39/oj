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

int main()
{
    nevikw39;
    int n, m, r = 0, a = 0;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n);
    vector<int> d(n, INT_MAX);
    while (m--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        g[a].emplace_back(b, w);
        g[b].emplace_back(a, w);
    }
    _heap<pair<int, int>, greater<pair<int, int>>> pq;
    vector<_heap<pair<int, int>, greater<pair<int, int>>>::point_iterator> pitr(n, nullptr);
    pitr[0] = pq.push({d[0] = 0, 0});
    while (pq.size())
    {
        auto t = pq.top();
        pq.pop();
        pitr[t.ND] = nullptr;
        for (const auto &i : g[t.ND])
            if (d[i.ST] > d[t.ND] + i.ND)
            {
                d[i.ST] = d[t.ND] + i.ND;
                if (pitr[i.ST] != nullptr)
                    pq.modify(pitr[i.ST], {d[i.ST], i.ST});
                else
                    pitr[i.ST] = pq.push({d[i.ST], i.ST});
            }
    }
    for (int i = 0; i < n; i++)
        if (d[i] == INT_MAX)
            ++a;
        else if (r < d[i])
            r = d[i];
    cout << r << '\n'
         << a << '\n';
    return 0;
}
