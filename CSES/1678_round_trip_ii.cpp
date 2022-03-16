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

vector<vector<int>> g;
vector<int> v, p;

bool dfs(int x)
{
    if (!~v[x])
    {
        stack<int> stk;
        for (int i = p[x]; i != x; i = p[i])
            stk.push(i);
        cout << stk.size() + 2 << '\n'
             << x + 1;
        while (stk.size())
        {
            cout << ' ' << stk.top() + 1;
            stk.pop();
        }
        cout << ' ' << x + 1 << '\n';
        return true;
    }
    v[x] = -1;
    for (const int &i : g[x])
    {
        p[i] = x;
        if (v[i] != 1 && dfs(i))
            return true;
    }
    v[x] = 1;
    return false;
}

int main()
{
    nevikw39;
    int n, m;
    cin >> n >> m;
    g.resize(n);
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        g[a - 1].push_back(b - 1);
    }
    v.resize(n);
    p.resize(n, -1);
    for (int i = 0; i < n; i++)
        if (!v[i] && dfs(i))
            return 0;
    cout << "IMPOSSIBLE\n";
    return 0;
}