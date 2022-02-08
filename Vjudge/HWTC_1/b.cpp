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

_hash<int, int> ht;

int64_t dfs(int a, int b, int c, int n)
{
    if (!n)
        return 0;
    if (ht[n] == a)
        return (1LL << n - 1) + dfs(a, c, b, n - 1);
    else if (ht[n] == c)
        return dfs(b, a, c, n - 1);
    cout << "No\n";
    exit(0);
}

int main()
{
    nevikw39;
    int n = 0;
    for (int i = 0; i < 3; i++)
    {
        int m;
        cin >> m;
        n += m;
        while (m--)
        {
            int x;
            cin >> x;
            ht[x] = i;
        }
    }
    cout << dfs(0, 1, 2, n) << '\n';
    return 0;
}