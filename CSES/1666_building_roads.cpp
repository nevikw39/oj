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
    vector<int> p, s;

    disjoint_set(int _n) : n(_n), g(_n)
    {
        p.resize(n);
        iota(ALL(p), 0);
        s.resize(n, 1);
    }

    int find(int x) { return x == p[x] ? x : p[x] = find(p[x]); }

    void unite(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a == b)
            return;
        if (s[a] < s[b])
            swap(a, b);
        p[b] = a;
        s[a] += s[b];
        --g;
    }
};

int main()
{
    nevikw39;
    int n, m;
    cin >> n >> m;
    disjoint_set dsu(n);
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        dsu.unite(a, b);
    }
    cout << dsu.g - 1 << '\n';
    vector<int> v;
    for (int i = 0; i < n; i++)
        if (i == dsu.find(i))
            v.push_back(i);
    for (int i = 1; i < dsu.g; i++)
        cout << v[i - 1] + 1 << ' ' << v[i] + 1 << '\n';
    return 0;
}