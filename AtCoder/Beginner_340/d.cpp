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

int main()
{
    nevikw39;
    int n;
    cin >> n;
    vector<tuple<int, int, int>> abx(n - 1);
    for (auto &[a, b, x] : abx)
        cin >> a >> b >> x;
    vector<int64_t> d(n, numeric_limits<int64_t>::max());
    _heap<pair<int64_t, int>> pq;
    vector<decltype(pq)::point_iterator> itrs(n);
    itrs[0] = pq.push({d[0] = 0, 0});
    while (pq.size())
    {
        int t = pq.top().ND;
        pq.pop();
        itrs[t] = nullptr;
        if (n - t == 1)
            continue;
        auto [a, b, x] = abx[t];
        if (d[t + 1] > d[t] + a)
        {
            if (itrs[t + 1] != nullptr)
                pq.modify(itrs[t + 1], {d[t + 1] = d[t] + a, t + 1});
            else
                itrs[t + 1] = pq.push({d[t + 1] = d[t] + a, t + 1});
        }
        if (d[x - 1] > d[t] + b)
        {
            if (itrs[x - 1] != nullptr)
                pq.modify(itrs[x - 1], {d[x - 1] = d[t] + b, x - 1});
            else
                itrs[x - 1] = pq.push({d[x - 1] = d[t] + b, x - 1});
        }
    }
    cout << d.back() << '\n';
    return 0;
}
