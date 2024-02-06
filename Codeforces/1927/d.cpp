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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a)
        cin >> i;
    vector<vector<int>> st_min(n, vector<int>(__lg(n) + 1)), st_max(n, vector<int>(__lg(n) + 1)); // Sparse Table
    for (int i = 0; i < n; i++)
        st_min[i][0] = i;
    for (int j = 1; j <= __lg(n); j++)
        for (int i = 0; i + (1 << j) <= n; i++)
            st_min[i][j] = a[st_min[i][j - 1]] < a[st_min[i + (1 << j - 1)][j - 1]] ? st_min[i][j - 1] : st_min[i + (1 << j - 1)][j - 1];
    for (int i = 0; i < n; i++)
        st_max[i][0] = i;
    for (int j = 1; j <= __lg(n); j++)
        for (int i = 0; i + (1 << j) <= n; i++)
            st_max[i][j] = a[st_max[i][j - 1]] > a[st_max[i + (1 << j - 1)][j - 1]] ? st_max[i][j - 1] : st_max[i + (1 << j - 1)][j - 1];
    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        --l;
        --r;
        int x = __lg(r - l + 1), mn = a[st_min[l][x]] < a[st_min[r - (1 << x) + 1][x]] ? st_min[l][x] : st_min[r - (1 << x) + 1][x], mx = a[st_max[l][x]] > a[st_max[r - (1 << x) + 1][x]] ? st_max[l][x] : st_max[r - (1 << x) + 1][x];
        if (a[mn] != a[mx])
            cout << mn + 1 << ' ' << mx + 1 << '\n';
        else
            cout << "-1 -1\n";
    }
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
