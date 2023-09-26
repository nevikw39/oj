/**                  _ _              _____ ___
 *  _ __   _____   _(_) | ____      _|___ // _ \
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/
 **/
#include <bits/extc++.h>
#ifndef nevikw39
#define nevikw39 cin.tie(nullptr)->sync_with_stdio(false)
// #pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
// #pragma GCC target("abm,bmi,bmi2,mmx,sse,sse2,sse3,ssse3,sse4,popcnt,avx,avx2,fma,tune=native")
// #pragma comment(linker, "/stack:200000000")
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

constexpr int M = 31;

vector<array<int, M>> v;

int f(int l, int r)
{
    bitset<M> bs;
    for (int i = 0; i < M; i++)
        if (v[r][i] - (l ? v[l - 1][i] : 0) == r - l + 1)
            bs[i] = true;
    return bs.to_ulong();
}

void solve()
{
    int n, q;
    cin >> n;
    v.resize(n);
    for (int i = 0, a; i < n; i++)
    {
        cin >> a;
        for (int j = 0; j < M; j++)
            v[i][j] = !!(a & 1 << j) + (i ? v[i - 1][j] : 0);
    }
    cin >> q;
    while (q--)
    {
        int l, k;
        cin >> l >> k;
        int r = --l;
        for (int jump = n >> 1; jump; jump >>= 1)
            while (r + jump < n && f(l, r + jump) >= k)
                r += jump;
        cout << (f(l, r) >= k ? r + 1 : -1) << ' ';
    }
    cout << '\n';
}

int main()
{
    nevikw39;
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
