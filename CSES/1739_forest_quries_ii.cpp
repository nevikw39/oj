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
    static inline int lowbit(int x) { return x & -x; }

    bit(int n) { v.resize(n + 1); }

    void update(int x, int val = 1)
    {
        for (int n = v.size(); x < n; x += lowbit(x))
            v[x] += val;
    }

    int query(int x)
    {
        int y = 0;
        for (; x > 0; x -= lowbit(x))
            y += v[x];
        return y;
    }
};

struct bit2d
{
    int n;
    vector<bit> v;
    static inline int lowbit(int x) { return x & -x; }

    bit2d(int _n) : n(_n) { v.resize(n + 1, bit(n)); }

    int query(int x, int y)
    {
        int z = 0;
        for (; x; x -= lowbit(x))
            z += v[x].query(y);
        return z;
    }

    void update(int x, int y, int val = 1)
    {
        for (; x <= n; x += lowbit(x))
            v[x].update(y, val);
    }
};

int main()
{
    nevikw39;
    int n, q;
    cin >> n >> q;
    bit2d b(n);
    vector<vector<bool>> v(n + 1, vector<bool>(n + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            char c;
            cin >> c;
            if (c == '*')
            {
                b.update(i, j);
                v[i][j] = true;
            }
        }
    while (q--)
    {
        char c;
        cin >> c;
        if (c == '1')
        {
            int x, y;
            cin >> x >> y;
            b.update(x, y, v[x][y] ? -1 : 1);
            v[x][y].flip();
        }
        else
        {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            cout << b.query(x2, y2) - b.query(x2, y1 - 1) - b.query(x1 - 1, y2) + b.query(x1 - 1, y1 - 1) << '\n';
        }
    }
    return 0;
}