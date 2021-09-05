/**                  _ _              _____ ___  
 *  _ __   _____   _(_) | ____      _|___ // _ \ 
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/ 
 **/
#include <atcoder/all>
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
using namespace atcoder;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
template <typename T, typename Cmp = less<T>, typename Tag = pairing_heap_tag>
using _heap = __gnu_pbds::priority_queue<T, Cmp, Tag>;
template <typename K, typename M = null_type>
using _hash = gp_hash_table<K, M>;
template <typename K, typename M = null_type, typename Cmp = less<K>, typename T = rb_tree_tag>
using _tree = tree<K, M, Cmp, T, tree_order_statistics_node_update>;

vector<vector<int>> adj;
vector<int> v;

bool dfs(int x)
{
    if (v[x] == 1)
        return false;
    if (v[x] == 2)
        return true;
    v[x] = 1;
    for (const int &i : adj[x])
        if (!dfs(i))
            return false;
    v[x] = 2;
    return true;
}

int main()
{
    nevikw39;
    int n, m;
    cin >> n >> m;
    adj.resize(n + 1);
    v.resize(n + 1);
    while (m--)
    {
        int k;
        cin >> k;
        vector<int> a(k);
        for (int &i : a)
            cin >> i;
        for (int i = 1; i < k; i++)
            adj[a[i - 1]].push_back(a[i]);
    }
    for (int i = 1; i <= n; i++)
        if (!v[i] && !dfs(i))
        {
            cout << "No\n";
            return 0;
        }
    cout << "Yes\n";
    return 0;
}