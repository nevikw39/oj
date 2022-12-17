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

int n;
vector<int> sz;
vector<vector<int>> t;

void dfs(int x, int p = -1)
{
    int w = 0;
    for (int i : t[x])
        if (i != p)
        {
            dfs(i, x);
            sz[x] += sz[i];
            w = max(w, sz[i]);
        }
    if (max(w, n - sz[x]) <= n >> 1)
    {
        cout << x + 1 << '\n';
        exit(EXIT_SUCCESS);
    }
}

int main()
{
    nevikw39;
    cin >> n;
    sz.assign(n, 1);
    t.assign(n, {});
    for (int i = 1, a, b; i < n; i++)
    {
        cin >> a >> b;
        --a, --b;
        t[a].push_back(b);
        t[b].push_back(a);
    }
    dfs(0);
    assert(false);
    return 0;
}
