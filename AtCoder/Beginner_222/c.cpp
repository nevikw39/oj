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

int main()
{
    nevikw39;
    int n, m;
    cin >> n >> m;
    vector<string> a(n << 1);
    for (auto &i : a)
        cin >> i;
    vector<pair<int, int>> v(n << 1);
    for (int i = 0; i < n << 1; i++)
        v[i].ND = i;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            auto &x = v[j << 1], &y = v[j << 1 | 1];
            if (a[x.ND][i] == a[y.ND][i])
                continue;
            if (a[x.ND][i] == 'G' && a[y.ND][i] == 'C' || a[x.ND][i] == 'C' && a[y.ND][i] == 'P' || a[x.ND][i] == 'P' && a[y.ND][i] == 'G')
                ++x.ST;
            else
                ++y.ST;
        }
        sort(ALL(v), [](const auto &l, const auto &r)
             { return l.ST != r.ST ? l.ST > r.ST : l.ND < r.ND; });
    }
    for (const auto &i : v)
        cout << i.ND + 1 << '\n';
    return 0;
}