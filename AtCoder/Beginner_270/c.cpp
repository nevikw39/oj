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

int n, x, y;
vector<vector<int>> t;
vector<int> p;

bool dfs(int x, int f = -1)
{
    if (x == y)
        return true;
    for (int i : t[x])
        if (i != f)
        {
            p.push_back(i);
            if (dfs(i, x))
                return true;
            assert(p.back() == i);
            p.pop_back();
        }
    return false;
}

int main()
{
    nevikw39;
    cin >> n >> x >> y;
    --x;
    --y;
    t.assign(n, {});
    for (int i = 1, u, v; i < n; i++)
    {
        cin >> u >> v;
        --u;
        --v;
        t[u].push_back(v);
        t[v].push_back(u);
    }
    dfs(x);
    cout << x + 1;
    for (int i : p)
        cout << ' ' << i + 1;
    cout << '\n';
    return 0;
}
