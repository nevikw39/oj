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

int n, sum;
vector<int> a, s;
vector<bool> v;

bool dfs(int r, int x = 0, int y = 0)
{
    if (y >= sum / r)
        return true;
    for (int i = x; i < n; i++)
    {
        if (v[i] || i && a[i] == a[i - 1] && !v[i - 1] || s[y] + a[i] > r)
            continue;
        v[i] = true;
        s[y] += a[i];
        if (s[y] == r)
        {
            if (dfs(r, 0, y + 1))
                return true;
        }
        else if (s[y] < r)
        {
            if (dfs(r, i + 1, y))
                return true;
        }
        v[i] = false;
        s[y] -= a[i];
        if (s[y] + v[i] == r || !s[y])
            return false;
    }
    return false;
}

int main()
{
    nevikw39;
    while (cin >> n && n)
    {
        a.resize(n);
        v.assign(n, false);
        for (int &i : a)
            cin >> i;
        sort(ALL(a), greater<int>());
        s.assign(sum = accumulate(ALL(a), 0), 0);
        for (int i = a.front(); i <= sum; i++)
            if (!(sum % i) && dfs(i))
            {
                cout << i << '\n';
                break;
            }
    }
    return 0;
}
