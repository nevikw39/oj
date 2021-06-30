/**                  _ _              _____ ___  
 *  _ __   _____   _(_) | ____      _|___ // _ \ 
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/ 
 **/
#include <bits/extc++.h>
#include <bits/stdc++.h>
#ifndef nevikw39
#define nevikw39      \
    cin.tie(nullptr); \
    ios::sync_with_stdio(false);
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("abm,bmi,bmi2,mmx,sse,sse2,sse3,ssse3,sse4,popcnt,avx,avx2,fma,tune=native")
#pragma comment(linker, "/stack:200000000")
struct _cerr
{
    template <typename T>
    _cerr &operator<<(const T &x) { return *this; }
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
template <typename K, typename M = null_type, typename Cmp = less<K>, typename T = rb_tree_tag>
using _tree = __gnu_pbds::tree<K, M, Cmp, T, tree_order_statistics_node_update>;
template <typename T>
using _heap = __gnu_pbds::priority_queue<T>;
template <typename K, typename M = null_type>
using _hash = gp_hash_table<K, M>;

int main()
{
    nevikw39;
    long long K, n, m, r = LLONG_MIN;
    cin >> K >> n >> m;
    vector<vector<long long>> v(n, vector<long long>(m));
    for (auto &i : v)
        for (auto &j : i)
            cin >> j;
    vector<long long> w(m);
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
        {
            if (i == j)
                for (int k = 0; k < m; k++)
                    w[k] = v[i][k];
            else
                for (int k = 0; k < m; k++)
                    w[k] += v[j][k];
            _tree<long long> t;
            t.insert(0);
            long long s = 0;
            for (int k = 0; k < m; k++)
            {
                s += w[k];
                auto itr = t.lower_bound(s - K);
                if (itr != t.end())
                    r = max(r, s - *itr);
                t.insert(s);
            }
        }
    cout << r << '\n';
    return 0;
}