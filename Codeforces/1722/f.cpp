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

void solve()
{
    static const pair<int, int> dirs[] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int n, m, x = 1;
    cin >> n >> m;
    vector<string> v(n);
    for (auto &row : v)
        cin >> row;
    auto f = [&](int i, int j)
    { return 0 <= i && i < n && 0 <= j && j < m; };
    vector<vector<int>> w(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (v[i][j] == '*' && !w[i][j])
            {
                w[i][j] = 1;
                for (int k = 0; k < 4; k++)
                {
                    int i1 = i + dirs[k].ST, j1 = j + dirs[k].ND, i2 = i + dirs[k + 1 & 3].ST, j2 = j + dirs[k + 1 & 3].ND;
                    if (f(i1, j1) && f(i2, j2) && v[i1][j1] == '*' && v[i2][j2] == '*')
                    {
                        w[i][j] = w[i1][j1] = w[i2][j2] = ++x;
                        break;
                    }
                }
            }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (w[i][j] == 1)
            {
                cout << "no\n";
                return;
            }
            else if (w[i][j])
                for (int di = -1; di <= 1; di++)
                    for (int dj = -1; dj <= 1; dj++)
                        if (f(i + di, j + dj) && w[i + di][j + dj] && w[i + di][j + dj] != w[i][j])
                        {
                            cout << "no\n";
                            return;
                        }
    cout << "yes\n";
}

int main()
{
    nevikw39;
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
