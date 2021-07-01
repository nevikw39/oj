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
template <typename T>
using _heap = __gnu_pbds::priority_queue<T>;
template <typename K, typename M = null_type>
using _hash = gp_hash_table<K, M>;
template <typename K, typename M = null_type, typename Cmp = less<K>, typename T = rb_tree_tag>
using _tree = tree<K, M, Cmp, T, tree_order_statistics_node_update>;

int main()
{
    nevikw39;
    long long n, r, t = 0;
    cin >> n;
    vector<long long> k(n + 1), p(n + 1), h(n + 1);
    queue<long long> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> k[i];
        if (!k[i])
            q.push(i);
        for (int j = 0; j < k[i]; j++)
        {
            long long x;
            cin >> x;
            p[x] = i;
        }
    }
    while (q.size())
    {
        auto f = q.front();
        q.pop();
        t += h[f];
        if (!p[f])
        {
            r = f;
            break;
        }
        h[p[f]] = max(h[p[f]], h[f] + 1);
        if (!--k[p[f]])
            q.push(p[f]);
    }
    cout << r << '\n' << t << '\n';
    return 0;
}