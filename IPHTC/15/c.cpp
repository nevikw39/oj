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
#pragma GCC target("tune=native")
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

constexpr pair<int, int> dirs[] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int main()
{
    nevikw39;
    int n, m, r = -1, t = 0;
    cin >> n >> m;
    vector<string> v(n);
    for (auto &i : v)
        cin >> i;
    queue<tuple<int, int, int>> q;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (v[i][j] == 'I')
                q.emplace(i, j, 0);
            else if (v[i][j] == 'T')
                ++t;
    while (q.size())
    {
        int i, j, d;
        tie(i, j, d) = q.front();
        q.pop();
        if (v[i][j] == 'C')
            continue;
        if (v[i][j] == 'T')
        {
            r = max(r, d);
            if (!--t)
                break;
        }
        v[i][j] = 'C';
        for (auto &dir : dirs)
        {
            int x = i + dir.ST, y = j + dir.ND;
            if (0 <= x && x < n && 0 <= y && y < m)
                q.emplace(x, y, d + 1);
        }
    }
    cout << (t ? -1 : r) << '\n';
    return 0;
}