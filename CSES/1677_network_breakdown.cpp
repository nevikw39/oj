/**                  _ _              _____ ___
 *  _ __   _____   _(_) | ____      _|___ // _ \
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/
 **/
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
using namespace __gnu_cxx;
using namespace __gnu_pbds;
template <typename T, typename Cmp = greater<T>, typename Tag = pairing_heap_tag>
using _heap = __gnu_pbds::priority_queue<T, Cmp, Tag>;
template <typename K, typename M = null_type>
using _hash = gp_hash_table<K, M>;
template <typename K, typename M = null_type, typename Cmp = less<K>, typename T = rb_tree_tag>
using _tree = tree<K, M, Cmp, T, tree_order_statistics_node_update>;

struct disjoint_set_undo
{
    int n, g;
    vector<int> p, sz;
    stack<tuple<int, int, int>> history;

    disjoint_set_undo() = default;
    disjoint_set_undo(int _n) : n(_n), g(_n), p(_n), sz(_n, 1) { iota(ALL(p), 0); }

    int find(int x) { return x == p[x] ? x : find(p[x]); }

    bool unite(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a == b)
            return false;
        if (sz[a] < sz[b])
            swap(a, b);
        history.emplace(a, b, sz[b]);
        --g;
        p[b] = a;
        sz[a] += sz[b];
        return true;
    }

    void undo()
    {
        auto [a, b, s] = history.top();
        history.pop();
        ++g;
        p[b] = b;
        sz[a] -= s;
    }
} dsu;

constexpr int64_t N = 1e5 + 5;
vector<pair<int, int>> time_segment_tree[N << 2];
vector<int> y;

void insert(int ql, int qr, pair<int, int> x, int i, int l, int r)
{
    if (l >= qr || ql >= r)
        return;
    if (ql <= l && r <= qr)
    {
        time_segment_tree[i].push_back(x);
        return;
    }
    int m = (l & r) + ((l ^ r) >> 1);
    if (qr <= m)
        insert(ql, qr, x, i << 1, l, m);
    else if (m <= ql)
        insert(ql, qr, x, i << 1 | 1, m, r);
    else
    {
        insert(ql, qr, x, i << 1, l, m);
        insert(ql, qr, x, i << 1 | 1, m, r);
    }
}

void traverse(int i, int l, int r)
{
    int cnt = 0;
    for (auto [a, b] : time_segment_tree[i])
        if (dsu.unite(a, b))
            ++cnt;
    time_segment_tree[i].clear();
    if (r - l == 1)
        y[l] = dsu.g;
    else
    {
        int m = (l & r) + ((l ^ r) >> 1);
        traverse(i << 1, l, m);
        traverse(i << 1 | 1, m, r);
    }
    while (cnt--)
        dsu.undo();
}

int main()
{
    nevikw39;
    int n, m, k;
    cin >> n >> m >> k;
    dsu = disjoint_set_undo(n);
    y.assign(k, 0);
    _hash<int64_t, vector<int>> hm;
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        if (a > b)
            swap(a, b);
        hm[a * N + b].push_back(0);
    }
    for (int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        if (a > b)
            swap(a, b);
        insert(hm[a * N + b].back(), i, {a, b}, 1, 0, k);
        hm[a * N + b].pop_back();
    }
    for (auto [x, v] : hm)
    {
        int a = x / N, b = x % N;
        for (int i : v)
            insert(i, k, {a, b}, 1, 0, k);
    }
    traverse(1, 0, k);
    copy(ALL(y), ostream_iterator<int>(cout, " "));
    return 0;
}
