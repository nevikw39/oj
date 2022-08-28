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

constexpr int N = 5e4 + 5;

auto solve()
{
    int n, r, c, x, y;
    string s;
    cin >> n >> r >> c >> x >> y >> s;
    _tree<int> row[N], col[N];
    row[x].insert(y);
    col[y].insert(x);
    for (char c : s)
    {
        int mn = 0, mx = N;
        switch (c)
        {
        case 'E':
            while (mn + 1 < mx)
            {
                int m = (mn & mx) + ((mn ^ mx) >> 1), yp = y + m;
                if (row[x].order_of_key(yp + 1) - row[x].order_of_key(y) == yp + 1 - y)
                    mn = m;
                else
                    mx = m;
            }
            y += mx;
            break;
        case 'W':
            while (mn + 1 < mx)
            {
                int m = (mn & mx) + ((mn ^ mx) >> 1), yp = y - m;
                if (row[x].order_of_key(y) - row[x].order_of_key(yp) == y - yp)
                    mn = m;
                else
                    mx = m;
            }
            y -= mx;
            break;
        case 'S':
            while (mn + 1 < mx)
            {
                int m = (mn & mx) + ((mn ^ mx) >> 1), xp = x + m;
                if (col[y].order_of_key(xp + 1) - col[y].order_of_key(x) == xp + 1 - x)
                    mn = m;
                else
                    mx = m;
            }
            x += mx;
            break;
        case 'N':
            while (mn + 1 < mx)
            {
                int m = (mn & mx) + ((mn ^ mx) >> 1), xp = x - m;
                if (col[y].order_of_key(x) - col[y].order_of_key(xp) == x - xp)
                    mn = m;
                else
                    mx = m;
            }
            x -= mx;
        }
        row[x].insert(y);
        col[y].insert(x);
    }
    stringstream ss;
    ss << x << ' ' << y;
    return ss.str();
}

int main()
{
    nevikw39;
    int i = 0, t;
    cin >> t;
    while (i < t)
        cout << "Case #" << ++i << ": " << solve() << '\n';
    return 0;
}