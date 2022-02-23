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
template <typename T, typename Cmp = less<T>, typename Tag = pairing_heap_tag>
using _heap = __gnu_pbds::priority_queue<T, Cmp, Tag>;
template <typename K, typename M = null_type>
using _hash = gp_hash_table<K, M>;
template <typename K, typename M = null_type, typename Cmp = less<K>, typename T = rb_tree_tag>
using _tree = tree<K, M, Cmp, T, tree_order_statistics_node_update>;

int main()
{
    nevikw39;
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, int>> e(m);
    for (auto &[a, b, c] : e)
        cin >> a >> b >> c;
    vector<int64_t> d(n, INT64_MAX >> 1);
    vector<int> p(n, -1);
    d[0] = 0;
    int x;
    for (int k = 0; k < n; k++)
    {
        x = -1;
        for (const auto &[a, b, c] : e)
            if (d[b - 1] > d[a - 1] + c)
            {
                d[b - 1] = d[a - 1] + c;
                p[b - 1] = a - 1;
                x = b - 1;
            }
    }
    if (!~x)
    {
        cout << "NO\n";
        return 0;
    }
    while (n--)
        x = p[x];
    deque<int> dq;
    for (int i = x; i != x || dq.empty(); i = p[i])
        dq.push_front(i);
    cout << "YES\n"
         << x + 1;
    for (const int &i : dq)
        cout << ' ' << i + 1;
    cout << '\n';
    return 0;
}