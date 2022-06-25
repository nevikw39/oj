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

int m;
vector<pair<int, __int128_t>> v[2];

int f(int x, bool y)
{
    if (x % m)
    {
        v[y].emplace_back(x, 1);
        return 1;
    }
    f(x / m, y);
    return v[y].back().ND *= m;
}

void solve()
{
    v[0].clear();
    v[1].clear();
    int n, k;
    cin >> n >> m;
    vector<int> a(n);
    for (int &i : a)
    {
        cin >> i;
        f(i, false);
        while (v[0].size() > 1 && v[0].rbegin()->ST == (v[0].rbegin() + 1)->ST)
        {
            auto b = v[0].back();
            v[0].pop_back();
            v[0].back().ND += b.ND;
        }
    }
    cin >> k;
    vector<int> b(k);
    for (int &i : b)
    {
        cin >> i;
        f(i, true);
        while (v[1].size() > 1 && v[1].rbegin()->ST == (v[1].rbegin() + 1)->ST)
        {
            auto b = v[1].back();
            v[1].pop_back();
            v[1].back().ND += b.ND;
        }
    }
    cout << (v[0] == v[1] ? "yes\n" : "no\n");
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
