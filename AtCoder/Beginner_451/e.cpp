/**                  _ _              _____ ___
 *  _ __   _____   _(_) | ____      _|___ // _ \
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/
 **/
#include <atcoder/all>
#include <bits/extc++.h>
#ifndef nevikw39
#define nevikw39 cin.tie(nullptr)->sync_with_stdio(false)
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
template <typename T, typename Cmp = greater<T>, typename Tag = pairing_heap_tag>
using _heap = __gnu_pbds::priority_queue<T, Cmp, Tag>;
template <typename K, typename M = null_type>
using _hash = gp_hash_table<K, M>;
template <typename K, typename M = null_type, typename Cmp = less<K>, typename T = rb_tree_tag>
using _tree = tree<K, M, Cmp, T, tree_order_statistics_node_update>;

int main()
{
    nevikw39;
    int n;
    cin >> n;
    vector a(n, vector<int>(n));
    for (int i : views::iota(0, n))
    {
        for (int j : views::iota(0, i))
            a[i][j] = a[j][i];
        a[i][i] = 0;
        for (int j : views::iota(i + 1, n))
            cin >> a[i][j];
    }
    vector<vector<pair<int, int>>> t(n);
    vector<int> d(n, numeric_limits<int>::max()), mst(n, -1);
    vector<bool> v(n);

    // Prim
    d[0] = 0;
    for (int k : views::iota(0, n))
    {
        int i = -1;
        for (int j : views::iota(0, n))
            if (!v[j] && (!~i || d[i] > d[j]))
                i = j;
        v[i] = true;
        if (~mst[i])
        {
            t[i].emplace_back(mst[i], a[i][mst[i]]);
            t[mst[i]].emplace_back(i, a[i][mst[i]]);
        }
        for (int j : views::iota(0, n))
            if (!v[j] && d[j] > a[i][j])
            {
                d[j] = a[i][j];
                mst[j] = i;
            }
    }

    for (int i : views::iota(0, n))
    {
        ranges::fill(d, numeric_limits<int>::max());
        ranges::fill(v, false);
        d[i] = 0;
        v[i] = true;
        queue<int> q;
        q.push(i);
        while (q.size())
        {
            const auto f = q.front();
            q.pop();
            for (const auto &[j, w] : t[f])
                if (!v[j])
                {
                    v[j] = true;
                    d[j] = d[f] + w;
                    q.push(j);
                }
        }
        if (a[i] != d)
        {
            println("No");
            return 0;
        }
    }
    println("Yes");
    return 0;
}
