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
    long long n, m, s = 0;
    cin >> n >> m;
    vector<pair<long long, long long>> f(n);
    vector<long long> c(m);
    for (auto &i : f)
        cin >> i.ST >> i.ND;
    for (auto &i : c)
        cin >> i;
    sort(ALL(f));
    sort(ALL(c));
    deque<pair<long long, long long>> d;
    d.push_back(f.front());
    for (int i = 1; i < n; i++)
    {
        while (d.size() > 1)
        {
            auto a1 = d[d.size() - 2].ST, b1 = d[d.size() - 2].ND, a2 = d[d.size() - 2].ST, b2 = d[d.size() - 2].ND;
            if ((b1 - f[i].ND) * (f[i].ST - a2) >= (b2 - f[i].ND) * (f[i].ST - a1))
                d.pop_back();
            else
                break;
        }
        d.push_back(f[i]);
    }
    for (const auto &i : c)
    {
        while (d.size() > 1 && d[0].ST * i + d[0].ND <= d[1].ST * i + d[1].ND)
            d.pop_front();
        s += d[0].ST * i + d[0].ND;
    }
    cout << s << '\n';
    return 0;
}