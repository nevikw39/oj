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
template <typename T, typename Cmp = greater<T>, typename Tag = pairing_heap_tag>
using _heap = __gnu_pbds::priority_queue<T, Cmp, Tag>;
template <typename K, typename M = null_type>
using _hash = gp_hash_table<K, M>;
template <typename K, typename M = null_type, typename Cmp = less<K>, typename T = rb_tree_tag>
using _tree = tree<K, M, Cmp, T, tree_order_statistics_node_update>;

vector<vector<int>> t;
vector<int64_t> sz, v;

int n;

void dfs(bool flag, int x = 0, int p = -1, int d = 0)
{
    if (!flag)
    {
        v[0] += d;
        sz[x] = 1;
    }
    for (const int &i : t[x])
    {
        if (i == p)
            continue;
        if (flag)
            v[i] = v[x] + n - (sz[i] << 1);
        dfs(flag, i, x, d + 1);
        if (!flag)
            sz[x] += sz[i];
    }
}

int main()
{
    nevikw39;
    cin >> n;
    t.resize(n);
    sz.resize(n);
    v.resize(n);
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        t[a].push_back(b);
        t[b].push_back(a);
    }
    dfs(false);
    dfs(true);
    for (const auto &i : v)
        cout << i << ' ';
    cout << '\n';
    return 0;
}