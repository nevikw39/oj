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
        int n, s, l = 0, r = 0;
        cin >> n >> s;
        vector<int> a(n);
        for (int &i : a)
            cin >> i;
        pair<int, int> p{-1, -1};
        int64_t ps = s;
        while (l < n && r < n)
        {
            if (ps + a[r] < 0)
                ps -= a[l++];
            else
                ps += a[r++];
            if (p.ND - p.ST < r - l)
                p = {l, r - 1};
        }
        if (p != make_pair(-1, -1))
            cout << p.ST + 1 << ' ' << p.ND + 1 << '\n';
        else
            cout << "-1\n";
    }
    return 0;
}