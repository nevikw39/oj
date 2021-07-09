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
template <typename T, typename Cmp = less<T>, typename Tag = pairing_heap_tag>
using _heap = __gnu_pbds::priority_queue<T, Cmp, Tag>;
template <typename K, typename M = null_type>
using _hash = gp_hash_table<K, M>;
template <typename K, typename M = null_type, typename Cmp = less<K>, typename T = rb_tree_tag>
using _tree = tree<K, M, Cmp, T, tree_order_statistics_node_update>;

struct disjoint_set
{
    int n, g;
    vector<int> p, r;
    disjoint_set(int _n) : n(_n + 1)
    {
        g = n;
        r = vector<int>(n, 1);
        for (int i = 0; i < n;)
            p.push_back(i++);
    }
    int find(int x)
    {
        return p[x] == x ? x : p[x] = find(p[x]);
    }
    bool unite(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
            return false;
        --g;
        if (r[x] < r[y])
        {
            p[x] = y;
            r[y] += r[x];
        }
        else
        {
            p[y] = x;
            r[x] += r[y];
        }
        return true;
    }
};

int main()
{
    nevikw39;
    int n, k, mn, mx;
    cin >> n >> k;
    vector<int> v(n);
    disjoint_set dsu(n);
    multiset<int> ms;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        if (v[i])
        {
            ms.insert(1);
            if (i && v[i - 1])
            {
                ms.erase(ms.find(dsu.r[dsu.find(i)]));
                ms.erase(ms.find(dsu.r[dsu.find(i - 1)]));
                dsu.unite(i, i - 1);
                ms.insert(dsu.r[dsu.find(i)]);
            }
        }
    }
    mn = *ms.begin(), mx = *ms.rbegin();
    while (k--)
    {
        int x;
        cin >> x;
        --x;
        v[x] = 1;
        ms.insert(1);
        if (x && v[x - 1])
        {
            ms.erase(ms.find(dsu.r[dsu.find(x)]));
            ms.erase(ms.find(dsu.r[dsu.find(x - 1)]));
            dsu.unite(x, x - 1);
            ms.insert(dsu.r[dsu.find(x)]);
        }
        if (x + 1 < n && v[x + 1])
        {
            ms.erase(ms.find(dsu.r[dsu.find(x)]));
            ms.erase(ms.find(dsu.r[dsu.find(x + 1)]));
            dsu.unite(x, x + 1);
            ms.insert(dsu.r[dsu.find(x)]);
        }
        mn += *ms.begin(), mx += *ms.rbegin();
    }
    cout << mx << '\n'
         << mn << '\n';
    return 0;
}