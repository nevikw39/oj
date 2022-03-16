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
using namespace __gnu_cxx;
using namespace __gnu_pbds;
template <typename T, typename Cmp = greater<T>, typename Tag = pairing_heap_tag>
using _heap = __gnu_pbds::priority_queue<T, Cmp, Tag>;
template <typename K, typename M = null_type>
using _hash = gp_hash_table<K, M>;
template <typename K, typename M = null_type, typename Cmp = less<K>, typename T = rb_tree_tag>
using _tree = tree<K, M, Cmp, T, tree_order_statistics_node_update>;

int main()
{
    nevikw39;
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int, int>>> g(n);
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a - 1].emplace_back(b - 1, c);
    }
    _heap<pair<int64_t, int>> pq;
    pq.push({0, 0});
    vector<_heap<int64_t, less<int64_t>>> pqs(n);
    pqs[0].push(0);
    while (pq.size())
    {
        auto [d, t] = pq.top();
        pq.pop();
        if (d > pqs[t].top())
            continue;
        for (const auto &[i, w] : g[t])
        {
            if (pqs[i].size() == k && d + w < pqs[i].top())
                pqs[i].pop();
            if (pqs[i].size() < k)
            {
                pqs[i].push(d + w);
                pq.push({d + w, i});
            }
        }
    }
    stack<int64_t> stk;
    while (pqs.back().size())
    {
        stk.push(pqs.back().top());
        pqs.back().pop();
    }
    while (stk.size())
    {
        cout << stk.top() << ' ';
        stk.pop();
    }
    cout << '\n';
    return 0;
}