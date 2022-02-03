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

vector<vector<int>> g;
vector<int> c;

void dfs(int x)
{
    if (~c[x])
        return;
    bitset<4> bs;
    for (const int &y : g[x])
        if (~c[y])
            bs[c[y]] = true;
    int i = 0;
    while (bs[i])
        assert(++i < 4);
    c[x] = i;
    for (const int &y : g[x])
        if (!~c[y])
            dfs(y);
}

int main()
{
    nevikw39;
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        g.clear();
        g.resize(n);
        while (m--)
        {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        c.clear();
        c.resize(n, -1);
        for (int i = 0; i < n; i++)
        {
            if (!~c[i])
                dfs(i);
            cout << c[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}

/*
2
6
11
1 5
2 1
0 1
3 1
4 3
4 5
0 5
3 0
2 4 
2 5 
4 0
5
9
0 1
4 0
4 1
3 4
2 4
0 2
1 2
3 1
2 3
*/