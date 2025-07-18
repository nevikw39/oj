/**                  _ _              _____ ___
 *  _ __   _____   _(_) | ____      _|___ // _ \
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/
 **/
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
using namespace __gnu_cxx;
using namespace __gnu_pbds;
template <typename T, typename Cmp = greater<T>, typename Tag = pairing_heap_tag>
using _heap = __gnu_pbds::priority_queue<T, Cmp, Tag>;
template <typename K, typename M = null_type>
using _hash = gp_hash_table<K, M>;
template <typename K, typename M = null_type, typename Cmp = less<K>, typename T = rb_tree_tag>
using _tree = tree<K, M, Cmp, T, tree_order_statistics_node_update>;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m), l(n + 1), r(n + 1);
    for (int &i : a)
        cin >> i;
    for (int &i : b)
        cin >> i;
    for (int i = 0; i < n; i++)
    {
        l[i + 1] = l[i];
        if (l[i + 1] + 1 < m && a[i] >= b[l[i + 1]])
            ++l[i + 1];
    }
    ranges::reverse(b);
    for (int i = n - 1; i >= 0; i--)
    {
        r[i] = r[i + 1];
        if (r[i + 1] < m && a[i] >= b[r[i + 1]])
            ++r[i];
    }
    ranges::reverse(b);
    int k = numeric_limits<int>::max();
    for (int i : views::iota(0, n + 1))
        if (l[i] + r[i] >= m)
        {
            k = 0;
            break;
        }
        else if (l[i] + r[i] == m - 1)
            k = min(k, b[l[i]]);
    if (k < numeric_limits<int>::max())
        cout << k << '\n';
    else
        cout << "-1\n";
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
