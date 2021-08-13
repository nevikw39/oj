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

struct bit
{
    vector<int> v;
    bit(int n)
    {
        v.resize(n + 1);
    }
    int inline lowbit(int x)
    {
        return x & -x;
    }
    void update(int x, int val = 1)
    {
        for (int i = x, n = v.size(); i < n; i += lowbit(i))
            v[i] += val;
    }
    int query(int x)
    {
        int y = 0;
        for (int i = x; i > 0; i -= lowbit(i))
            y += v[i];
        return y;
    }
};

struct node
{
    int a, b, i;
    constexpr bool operator<(const node &x) const
    {
        return a != x.a ? a > x.a : b < x.b;
    }
};

int main()
{
    nevikw39;
    int64_t n, m = 0;
    cin >> n;
    vector<node> v(n);
    vector<int64_t> a(n);
    tree<int64_t, int64_t> cc;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].a >> v[i].b;
        v[i].i = i;
        cc[v[i].b] = 0;
    }
    for (auto &i : cc)
        i.ND = ++m;
    sort(ALL(v));
    bit b(m);
    b.update(cc[v[0].b]);
    for (int i = 1; i < n; i++)
    {
        a[v[i].i] = b.query(cc[v[i].b]);
        b.update(cc[v[i].b]);
    }
    for (const auto &i : a)
        cout << !!i << ' ';
    cout << '\n';
    fill(ALL(a), 0);
    fill(ALL(b.v), 0);
    b.update(1);
    b.update(cc[v[n - 1].b] + 1, -1);
    for (int i = n - 2; i >= 0; i--)
    {
        a[v[i].i] = b.query(cc[v[i].b]);
        b.update(1);
        b.update(cc[v[i].b] + 1, -1);
    }
    for (const auto &i : a)
        cout << !!i << ' ';
    cout << '\n';
    return 0;
}