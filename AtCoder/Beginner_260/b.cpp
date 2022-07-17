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
    int n, x, y, z;
    cin >> n >> x >> y >> z;
    vector<int> a(n), b(n), v(n);
    for (int &i : a)
        cin >> i;
    for (int &i : b)
        cin >> i;
    iota(ALL(v), 0);
    sort(ALL(v), [&](int l, int r)
         { return a[l] != a[r] ? a[l] > a[r] : l < r; });
    sort(x + ALL(v), [&](int l, int r)
         { return b[l] != b[r] ? b[l] > b[r] : l < r; });
    sort(y + x + ALL(v), [&](int l, int r)
         { return a[l] + b[l] != a[r] + b[r] ? a[l] + b[l] > a[r] + b[r] : l < r; });
    sort(v.begin(), v.begin() + x + y + z);
    for (int i = 0; i < x + y + z; i++)
        cout << v[i] + 1 << '\n';
    return 0;
}
