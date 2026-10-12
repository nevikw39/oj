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
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    std::copy_n(istream_iterator<int>(cin), n, a.begin());
    segtree<int64_t,
            [](auto x, auto y) { return x + y; },
            []() { return 0L; }>
        st(a | ranges::to<vector<int64_t>>());
    while (q--)
    {
        char c;
        cin >> c;
        int i, x, l, r;
        int64_t t;
        switch (c)
        {
        case '1':
            cin >> i >> x;
            st.set(i - 1, x);
            break;
        case '2':
            cin >> l >> t;
            println("{}", st.max_right(l - 1, [&](auto x) { return x < t; }) + 1);
            break;
        default:
            cin >> r >> t;
            println("{}", st.min_left(r, [&](auto x) { return x < t; }));
        }
    }
    return 0;
}
