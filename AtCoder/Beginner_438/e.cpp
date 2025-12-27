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

constexpr int LG = 31;

int main()
{
    nevikw39;
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    std::copy_n(istream_iterator<int>(cin), n, a.begin());
    vector st_a(n, array<int, LG>{});
    vector st_sum(n, array<int64_t, LG>{});
    for (int i : views::iota(0, n))
    {
        st_a[i][0] = a[i] - 1;
        st_sum[i][0] = i + 1;
    }
    for (int j = 1; j < LG; j++)
        for (int i = 0; i < n; i++)
        {
            const int mid = st_a[i][j - 1];
            st_a[i][j] = st_a[mid][j - 1];
            st_sum[i][j] = st_sum[i][j - 1] + st_sum[mid][j - 1];
        }
    while (q--)
    {
        int t, b;
        cin >> t >> b;
        --b;
        int64_t sum = 0;
        for (int j = 0; j < LG; j++)
            if ((t >> j) & 1)
            {
                sum += st_sum[b][j];
                b = st_a[b][j];
            }
        cout << sum << '\n';
    }
    return 0;
}
