/**                  _ _              _____ ___  
 *  _ __   _____   _(_) | ____      _|___ // _ \ 
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/ 
 **/
#include <atcoder/all>
#include <bits/extc++.h>
#ifndef nevikw39
#define nevikw39 cin.tie(nullptr)->sync_with_stdio(false)
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("abm,bmi,bmi2,mmx,sse,sse2,sse3,ssse3,sse4,popcnt,avx,avx2,fma,tune=native")
#pragma comment(linker, "/stack:200000000")
struct
{
    template <typename T>
    auto &operator<<(const T &x) { return *this; }
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
using namespace atcoder;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
template <typename T, typename Cmp = greater<T>, typename Tag = pairing_heap_tag>
using _heap = __gnu_pbds::priority_queue<T, Cmp, Tag>;
template <typename K, typename M = null_type>
using _hash = gp_hash_table<K, M>;
template <typename K, typename M = null_type, typename Cmp = less<K>, typename T = rb_tree_tag>
using _tree = tree<K, M, Cmp, T, tree_order_statistics_node_update>;

void dijkstra(int n, const vector<vector<pair<int, int>>> &g, int s, int t, vector<int64_t> &d)
{
    _heap<pair<int64_t, int>> pq;
    vector<decltype(pq)::point_iterator> itrs(n);
    itrs[s] = pq.push({d[s] = 0, s});
    while (pq.size())
    {
        if (pq.top().ND == t)
            break;
        const int t = pq.top().ND;
        pq.pop();
        itrs[t] = nullptr;
        for (const auto &[i, w] : g[t])
            if (d[i] > d[t] + w)
            {
                if (itrs[i] != nullptr)
                    pq.modify(itrs[i], {d[i] = d[t] + w, i});
                else
                    itrs[i] = pq.push({d[i] = d[t] + w, i});
            }
    }
}

int main()
{
    nevikw39;
    int n, m, x, y, c;
    cin >> n >> m >> x >> y >> c;
    vector g(n, vector<pair<int, int>>{});
    while (m-- > 1)
    {
        int x, y, c;
        cin >> x >> y >> c;
        g[x - 1].emplace_back(y - 1, c);
    }
    if (--x == --y)
    {
        println("{}", c);
        return 0;
    }
    vector d(n, numeric_limits<int64_t>::max() >> 1);
    dijkstra(n, g, y, x, d);
    if (d[x] != numeric_limits<int64_t>::max() >> 1)
        println("{}", c + d[x]);
    else
        println("-1");
    return 0;
}
