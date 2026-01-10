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
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> a(n);
    std::copy_n(istream_iterator<int>(cin), n, a.begin());
    ranges::sort(a, greater{});
    vector<int64_t> s{INT64_C(1) * a[0] * k};
    _heap<tuple<int64_t, int, int>, less<>> pq;
    pq.push({a[0] * (k - INT64_C(1)) + a[1], 1, 1});
    while (s.size() < x)
    {
        auto [d, lst, v] = pq.top();
        pq.pop();
        s.push_back(d);
        if (n - lst > 1)
            pq.push({d - a[lst] + a[lst + 1], lst + 1, v});
        if (v < k)
            pq.push({d - a[0] + a[lst], lst, v + 1});
    }
    ranges::copy(s, ostream_iterator<int64_t>(cout, "\n"));
    return 0;
}
