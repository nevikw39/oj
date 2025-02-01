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
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n), c(n);
    for (int &i : a)
        cin >> i;
    for (int &i : b)
        cin >> i;
    for (int &i : c)
        cin >> i;
    ranges::sort(a, greater<>());
    ranges::sort(b, greater<>());
    ranges::sort(c, greater<>());
    _heap<tuple<int64_t, int, int, int>, less<>> pq;
    tree<tuple<int, int, int>, null_type> t;
    auto add = [&](int i, int j, int k)
    {
        const auto v = INT64_C(1) * a[i] * b[j] + INT64_C(1) * b[j] * c[k] + INT64_C(1) * c[k] * a[i];
        if (i < n && j < n && k < n && t.find({i, j, k}) == t.end())
        {
            t.insert({i, j, k});
            pq.push({v, i, j, k});
        }
    };
    add(0, 0, 0);
    while (--k)
    {
        auto [v, i, j, k] = pq.top();
        pq.pop();
        add(i + 1, j, k);
        add(i, j + 1, k);
        add(i, j, k + 1);
    }
    cout << get<0>(pq.top()) << '\n';
    return 0;
}
