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

int mn, arr[5][5], offices[5], brr[5];

void f(int x = 0, int n = 0)
{
    if (n == 5)
    {
        int r = 0;
        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 5; j++)
            {
                int d = INT_MAX;
                for (int o : offices)
                    d = min(d, arr[i][j] * (abs(o / 5 - i) + abs(o % 5 - j)));
                r += d;
            }
        if (mn > r)
        {
            mn = r;
            memcpy(brr, offices, sizeof(brr));
        }
        return;
    }
    for (int i = x; i < 25; i++)
    {
        offices[n] = i;
        f(i + 1, n + 1);
    }
}

void solve()
{
    mn = INT_MAX;
    memset(arr, 0, sizeof(arr));
    int n;
    cin >> n;
    while (n--)
    {
        int r, c, p;
        cin >> r >> c >> p;
        arr[r][c] += p;
    }
    f();
    cout << *brr << ' ' << 1 [brr] << ' ' << 2 [brr] << ' ' << 3 [brr] << ' ' << 4 [brr] << '\n';
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