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
    vector<string> c(n);
    for (auto &i : c)
        cin >> i;
    vector a(n, vector(n, -1));
    queue<pair<int, int>> q;
    for (const int i : views::iota(0, n))
    {
        q.emplace(i, i);
        a[i][i] = 0;
    }
    for (const int i : views::iota(0, n))
        for (const int j : views::iota(0, n))
            if (i != j && c[i][j] != '-')
            {
                q.emplace(i, j);
                a[i][j] = 1;
            }
    while (q.size())
    {
        const auto [i, j] = q.front();
        q.pop();
        for (const int h : views::iota(0, n))
            for (const int k : views::iota(0, n))
                if (c[h][i] != '-' && c[h][i] == c[j][k] && !~a[h][k])
                {
                    q.emplace(h, k);
                    a[h][k] = a[i][j] + 2;
                }
    }
    for (const auto &i : a)
    {
        for (const int j : i)
            cout << j << ' ';
        cout << '\n';
    }
    return 0;
}
