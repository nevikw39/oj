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

constexpr int N = 1e6 + 6;
int segment_tree[N << 3], tag[N << 3];

void pull(int l, int r, int i)
{
    if (tag[i])
        segment_tree[i] = r - l + 1;
    else if (r != l)
        segment_tree[i] = segment_tree[i << 1] + segment_tree[i << 1 | 1];
    else
        segment_tree[i] = 0;
}

void update(int ql, int qr, int l, int r, int i, int v)
{
    if (ql <= l && r <= qr)
    {
        tag[i] += v;
        pull(l, r, i);
        return;
    }
    int m = (l & r) + ((l ^ r) >> 1);
    if (ql <= m)
        update(ql, qr, l, m, i << 1, v);
    if (m < qr)
        update(ql, qr, m + 1, r, i << 1 | 1, v);
    pull(l, r, i);
}

int main()
{
    nevikw39;
    int n;
    cin >> n;
    vector<tuple<int, int, int, int>> v(n << 1);
    for (int i = 0, x1, y1, x2, y2; i < n; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        v[i << 1] = {x1, y1, y2 - 1, 1};
        v[i << 1 | 1] = {x2, y1, y2 - 1, -1};
    }
    sort(ALL(v));
    int xp;
    int64_t r = 0;
    for (auto [x, y1, y2, w] : v)
    {
        r += 1LL * (x - xp) * segment_tree[1];
        xp = x;
        update(y1 + N, y2 + N, 1, N << 1, 1, w);
    }
    cout << r << '\n';
    return 0;
}