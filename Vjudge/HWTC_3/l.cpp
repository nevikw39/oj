/**                  _ _              _____ ___
 *  _ __   _____   _(_) | ____      _|___ // _ \
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/
 **/
#include "atcoder/all"
#include <bits/extc++.h>
#ifndef nevikw39
#define nevikw39 cin.tie(nullptr), ios::sync_with_stdio(false)
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("abm,bmi,bmi2,mmx,sse,sse2,sse3,ssse3,sse4,popcnt,avx,avx2,fma,tune=native")
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
template <typename T, typename Cmp = less<T>, typename Tag = pairing_heap_tag>
using _heap = __gnu_pbds::priority_queue<T, Cmp, Tag>;
template <typename K, typename M = null_type>
using _hash = gp_hash_table<K, M>;
template <typename K, typename M = null_type, typename Cmp = less<K>, typename T = rb_tree_tag>
using _tree = tree<K, M, Cmp, T, tree_order_statistics_node_update>;

vector<vector<int>> t;
vector<array<int, 2>> dp;

int dfs(int x, int p, bool c)
{
    if (dp[x][c])
        return dp[x][c];
    modint1000000007 y = 1;
    for (const int &i : t[x])
        if (i == p)
            continue;
        else if (c)
            y *= dfs(i, x, false) + dfs(i, x, true);
        else
            y *= dfs(i, x, true);
    return dp[x][c] = y.val();
}

int main()
{
    nevikw39;
    int n;
    cin >> n;
    t.resize(n);
    dp.resize(n);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        t[u].push_back(v);
        t[v].push_back(u);
    }
    cout << (dfs(0, -1, false) + dfs(0, -1, true)) % 1000000007 << '\n';
    return 0;
}