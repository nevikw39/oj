/**                  _ _              _____ ___
 *  _ __   _____   _(_) | ____      _|___ // _ \
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/
 **/
#include <bits/extc++.h>
#ifndef nevikw39
#define nevikw39 cin.tie(nullptr), ios::sync_with_stdio(false)
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("abm,bmi,bmi2,mmx,sse,sse2,sse3,ssse3,sse4,popcnt,avx,avx2,fma,tune=native")
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
    int t;
    cin >> t;
    for (int i = 0; i < t;)
    {
        int n, m, s, t;
        cin >> n >> m >> s >> t;
        vector<vector<pair<int, int>>> g(n);
        while (m--)
        {
            int u, v, w;
            cin >> u >> v >> w;
            g[u].emplace_back(w, v);
            g[v].emplace_back(w, u);
        }
        vector<int> d(n, INT_MAX);
        _heap<pair<int, int>, greater<pair<int, int>>> pq;
        pq.push({d[s] = 0, s});
        while (pq.size())
        {
            auto t = pq.top();
            pq.pop();
            if (d[t.ND] < t.ST)
                continue;
            for (const auto &i : g[t.ND])
                if (d[i.ND] > d[t.ND] + i.ST)
                    pq.push({d[i.ND] = d[t.ND] + i.ST, i.ND});
        }
        cout << "Case #" << ++i << ": ";
        if (d[t] != INT_MAX)
            cout << d[t] << '\n';
        else
            cout << "unreachable\n";
    }
    return 0;
}