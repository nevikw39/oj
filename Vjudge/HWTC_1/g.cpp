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

int main()
{
    nevikw39;
    int t;
    cin >> t;
    while (t--)
    {
        int n, mx = -1, mn = INT_MAX, r = 0;
        cin >> n;
        vector<int> a(n);
        for (int &i : a)
            cin >> i;
        for (int i = 0; i < n; i++)
            if (!~a[i])
            {
                if (i > 0 && ~a[i - 1])
                {
                    mx = max(mx, a[i - 1]);
                    mn = min(mn, a[i - 1]);
                }
                if (i + 1 < n && ~a[i + 1])
                {
                    mx = max(mx, a[i + 1]);
                    mn = min(mn, a[i + 1]);
                }
            }
        int k = ~mx ? (mx & mn) + ((mx ^ mn) >> 1) : 0;
        for (int i = 1; i < n; i++)
            r = max(r, abs((~a[i] ? a[i] : k) - (~a[i - 1] ? a[i - 1] : k)));
        cout << r << ' ' << k << '\n';
    }
    return 0;
}